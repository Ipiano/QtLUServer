#include "MessageIdentifiers.h"
#include "RakNetStatistics.h"
#include "RakNetTypes.h"
#include "QtRakNetworkFactory.h"
#include "ConsoleReaderThread.h"

#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <QTimer>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    QTextStream cin(stdin);
    QTextStream cout(stdout);

    // Pointers to the interfaces of our server and client.
    // Note we can easily have both in the same program
    QtRakPeer* server = QtRakNetworkFactory::GetQtRakPeer();
    //server->InitializeSecurity(0,0,0,0);
    int i = server->GetNumberOfAddresses();
    server->SetIncomingPassword("Rumpelstiltskin", (int)strlen("Rumpelstiltskin"));

    QVector<SystemAddress> clients;

    cout << "This is a sample implementation of a text based chat server." << endl;
    cout << "Connect to the project 'Chat Example Client'." << endl;

    unsigned int port;
    cout << "\nEnter a port number to listen on: " << flush;
    cin >> port;

    cout << "Starting server..." << endl;
    // Starting the server is very simple.  2 players allowed.
    // 0 means we don't care about a connectionValidationInteger, and false
    // for low priority threads
    SocketDescriptor socketDescriptor(port,0);
    bool b = server->Startup(32, 30, &socketDescriptor, 1 );
    server->SetMaximumIncomingConnections(2);
    if (b)
        cout << "Server started, waiting for connections." << endl;
    else
    {
        cout << "Server failed to start.  Terminating." << endl;
        QtRakNetworkFactory::DestroyQtRakPeer(server);
        exit(1);
    }
    server->SetOccasionalPing(true);

    cout << "My IP is " << server->GetLocalIP(0) << endl;
    cout << "'quit' to quit. 'stat' to show stats. 'ping' to ping.\n'ban' to ban an IP from connecting.\n'kick to kick the first connected player.\nType to talk." << endl;

    QObject::connect(server, &QtRakPeer::Recieve,
    [&server, &cin, &cout, &clients](unsigned int packetIdentifier, SystemIndex index, SystemAddress address, QByteArray data)
    {

        // Check if this is a network message packet
        switch (packetIdentifier)
        {
            case ID_DISCONNECTION_NOTIFICATION:
                  // Connection lost normally
                cout << "ID_DISCONNECTION_NOTIFICATION" << endl;
                break;


            case ID_NEW_INCOMING_CONNECTION:
                 // Somebody connected.  We have their IP now
                cout << "ID_NEW_INCOMING_CONNECTION from " << address.ToString() << endl;
                if(!clients.contains(address))
                    clients.push_back(address); // Record the player ID of the client
                break;

            case ID_MODIFIED_PACKET:
                // Cheater!
                cout << "ID_MODIFIED_PACKET" << endl;
                break;

            case ID_CONNECTION_LOST:
                // Couldn't deliver a reliable packet - i.e. the other system was abnormally
                // terminated
                cout << "ID_CONNECTION_LOST" << endl;
                clients.removeAll(address);
                break;

            default:
                // The server knows the static data of all clients, so we can prefix the message
                // With the name data
                cout << data << endl;

                // Relay the message.  We prefix the name for other clients.  This demonstrates
                // That messages can be changed on the server before being broadcast
                // Sending is the same as before
                for(SystemAddress s : clients)
                    server->Send(data, HIGH_PRIORITY, RELIABLE_ORDERED, 0, s, true);

                break;
        }
    });

    ConsoleReader reader;
    reader.start();
    QObject::connect(&reader, &ConsoleReader::gotLine,
    [&app, &cin, &cout, &clients, &server, &reader](QString input)
    {
        if (input == "quit")
        {
            cout << "Quitting." << endl;
            reader.stop();
            QTimer::singleShot(1, &app, &QCoreApplication::quit);
        }
        else if (input == "stat")
        {
            char message[2048];
            RakNetStatistics *rss = server->GetStatistics(server->GetSystemAddressFromIndex(0));
            StatisticsToString(rss, message, 2);
            cout << message << endl;
            cout << "Ping " << server->GetAveragePing(server->GetSystemAddressFromIndex(0)) << endl;
        }
        else if (input == "ping")
        {
            for(SystemAddress s : clients)
                server->Ping(s);
        }
        else
        {
            QByteArray out = QString("Server: " + input).toLatin1();
            // HIGH_PRIORITY doesn't actually matter here because we don't use any other priority
            // RELIABLE_ORDERED means make sure the message arrives in the right order
            // We arbitrarily pick 0 for the ordering stream
            // UNASSIGNED_SYSTEM_ADDRESS means don't exclude anyone from the broadcast
            // true means broadcast the message to everyone connected
            server->Send(out, HIGH_PRIORITY, RELIABLE_ORDERED, 0, UNASSIGNED_SYSTEM_ADDRESS, true);
        }
    });

    int out = app.exec();

    server->Shutdown(300);
    QtRakNetworkFactory::DestroyQtRakPeer(server);

    return out;
}
