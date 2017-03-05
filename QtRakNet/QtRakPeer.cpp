#include "QtRakPeer.h"
#include "./RakNet3.25/RakNetworkFactory.h"
#include "./RakNet3.25/RakSleep.h"

QtRakPeer::QtRakPeer(unsigned int sleepInterval, QObject *parent)
    : QObject(parent), _sleepInt(sleepInterval)
{
    _peer = RakNetworkFactory::GetRakPeerInterface();

    qRegisterMetaType<SystemAddress>("SystemAddress");
    qRegisterMetaType<SystemIndex>("SystemIndex");
}

QtRakPeer::~QtRakPeer()
{
    if(running())
    {
        Shutdown(0);
        _thread.waitForFinished();
    }

    RakNetworkFactory::DestroyRakPeerInterface(_peer);
}

void QtRakPeer::pollRakPeer()
{
    while(running())
    {
        RakSleep(_sleepInt);
        QMutexLocker lock(&_peerMutex);

        Packet* packet= _peer->Receive();

        lock.unlock();

        if(packet)
        {
            QByteArray data;
            unsigned int packetId = ID_UNKNOWN;
            data = QByteArray((char*)packet->data, std::max((unsigned int)packet->bitSize/8, (unsigned int)1));
            packetId = GetPacketIdentifier(data);
            emit Recieve(packetId, packet->systemIndex, packet->systemAddress, data);

            lock.relock();
            _peer->DeallocatePacket(packet);
        }
    }
}
