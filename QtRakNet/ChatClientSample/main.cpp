#include "MessageIdentifiers.h"
#include "RakNetStatistics.h"
#include "RakNetTypes.h"
#include "QtRakNetworkFactory.h"
#include "ConsoleReaderThread.h"

#include <QCoreApplication>
#include <QByteArray>
#include <QString>
#include <QTextStream>
#include <QTimer>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    QTextStream cout(stdout);
    QTextStream cin(stdin);

    // Pointers to the interfaces of our server and client.
    // Note we can easily have both in the same program
    QtRakPeer *client=QtRakNetworkFactory::GetQtRakPeer();
//	client->InitializeSecurity(0,0,0,0);

    // Record the first client that connects to us so we can pass it to the ping function
    SystemAddress clientID=UNASSIGNED_SYSTEM_ADDRESS;

    // Crude interface

    cout << "This is a sample implementation of a text based chat client." << endl;
    cout << "Connect to the project 'Chat Example Server'." << endl;

    unsigned int clientPort, serverPort;
    QString ip;

    // Get our input
    cout << "Enter the client port to listen on: " << flush;
    cin >> clientPort;

    cout << "Enter IP to connect to: " << flush;
    cin >> ip;
    client->AllowConnectionResponseIPMigration(false);

    cout << "Enter the port to connect to: " << endl;
    cin >> serverPort;

    // Connecting the client is very simple.  0 means we don't care about
    // a connectionValidationInteger, and false for low priority threads
    SocketDescriptor socketDescriptor(clientPort,0);
    client->Startup(1,30,&socketDescriptor, 1);
    client->SetOccasionalPing(true);
    bool b = client->Connect(ip.toLatin1().data(), serverPort, "Rumpelstiltskin", (int) strlen("Rumpelstiltskin"));

    if (b)
        cout << "Attempting connection" << endl;
    else
    {
        cout << "Bad connection attempt.  Terminating." << endl;
        QtRakNetworkFactory::DestroyQtRakPeer(client);
        exit(1);
    }

    cout << "'quit' to quit. 'stat' to show stats. 'ping' to ping. Type to talk." << endl;

    ConsoleReader reader;
    reader.start();
    QObject::connect(&reader, &ConsoleReader::gotLine,
    [&app, &client, &cout, &reader](QString message)
    {
        if (message == "quit")
        {
            cout << "Quitting..." << endl;
            reader.stop();
            QTimer::singleShot(1, &app, &QCoreApplication::quit);
        }

        else if (message == "stat")
        {
            char stats[2048];
            RakNetStatistics* rss=client->GetStatistics(client->GetSystemAddressFromIndex(0));
            StatisticsToString(rss, stats, 2);
            cout << stats << endl;
            cout << "Ping=" << client->GetAveragePing(client->GetSystemAddressFromIndex(0)) << endl;
        }

        else if (message == "ping")
        {
            if (client->GetSystemAddressFromIndex(0)!=UNASSIGNED_SYSTEM_ADDRESS)
                client->Ping(client->GetSystemAddressFromIndex(0));
        }

        else
        {
            // message is the data to send
            // strlen(message)+1 is to send the null terminator
            // HIGH_PRIORITY doesn't actually matter here because we don't use any other priority
            // RELIABLE_ORDERED means make sure the message arrives in the right order
            client->Send(message.toLatin1(), HIGH_PRIORITY, RELIABLE_ORDERED, 0, UNASSIGNED_SYSTEM_ADDRESS, true);
        }
    });

    QObject::connect(client, &QtRakPeer::Recieve,
    [&cout, &client](unsigned char packetIdentifier, SystemIndex index, SystemAddress address, QByteArray data)
    {
        // Check if this is a network message packet
        switch (packetIdentifier)
        {
            case ID_DISCONNECTION_NOTIFICATION:
                  // Connection lost normally
                cout << "ID_DISCONNECTION_NOTIFICATION" << endl;
                break;
            case ID_ALREADY_CONNECTED:
                // Connection lost normally
                cout << "ID_ALREADY_CONNECTED" << endl;
                break;
            case ID_REMOTE_DISCONNECTION_NOTIFICATION: // Server telling the clients of another client disconnecting gracefully.  You can manually broadcast this in a peer to peer enviroment if you want.
                cout << "ID_REMOTE_DISCONNECTION_NOTIFICATION" << endl;
                break;
            case ID_REMOTE_CONNECTION_LOST: // Server telling the clients of another client disconnecting forcefully.  You can manually broadcast this in a peer to peer enviroment if you want.
                cout << "ID_REMOTE_CONNECTION_LOST" << endl;
                break;
            case ID_REMOTE_NEW_INCOMING_CONNECTION: // Server telling the clients of another client connecting.  You can manually broadcast this in a peer to peer enviroment if you want.
                cout << "ID_REMOTE_NEW_INCOMING_CONNECTION" << endl;
                break;
            case ID_CONNECTION_BANNED: // Banned from this server
                cout << "We are banned from this server." << endl;
                break;
            case ID_CONNECTION_ATTEMPT_FAILED:
                cout << "Connection attempt failed" << endl;
                break;
            case ID_NO_FREE_INCOMING_CONNECTIONS:
                 // Sorry, the server is full.  I don't do anything here but
                // A real app should tell the user
                cout << "ID_NO_FREE_INCOMING_CONNECTIONS" << endl;
                break;
            case ID_MODIFIED_PACKET:
                // Cheater!
                cout << "ID_MODIFIED_PACKET" << endl;
                break;

            case ID_INVALID_PASSWORD:
                cout << "ID_INVALID_PASSWORD" << endl;
                break;

            case ID_CONNECTION_LOST:
                // Couldn't deliver a reliable packet - i.e. the other system was abnormally
                // terminated
                cout << "ID_CONNECTION_LOST" << endl;
                break;

            case ID_CONNECTION_REQUEST_ACCEPTED:
                // This tells the client they have connected
                cout << "ID_CONNECTION_REQUEST_ACCEPTED" << endl;
                break;
            default:
                    // It's a client, so just show the message
                    cout << data << endl;
                break;
        }
    });

    int out = app.exec();

    // Be nice and let the server know we quit.
    client->Shutdown(300);

    // We're done with the network
    QtRakNetworkFactory::DestroyQtRakPeer(client);

    return out;
}
