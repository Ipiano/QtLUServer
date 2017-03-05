#include "QtRakNetworkFactory.h"
#include "QtRakPeer.h"

QtRakPeer* QtRakNetworkFactory::GetQtRakPeer( void )
{
    return new QtRakPeer;
}

void QtRakNetworkFactory::DestroyQtRakPeer( QtRakPeer* i )
{
    delete ( QtRakPeer* ) i;
}
