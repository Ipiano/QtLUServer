#ifndef QTRAKEXPORTFACTORY_H
#define QTRAKEXPORTFACTORY_H

#include "./RakNet3.25/Export.h"
#include "QtRakPeer.h"

class RAK_DLL_EXPORT QtRakNetworkFactory
{
public:
    // For DLL's, these are user classes that you might want to new and delete.
    // You can't instantiate exported classes directly in your program.  The instantiation
    // has to take place inside the DLL.  So these functions will do the news and deletes for you.
    // if you're using the source or static library you don't need these functions, but can use them if you want.
    static QtRakPeer* GetQtRakPeer( void );


    // To delete the object returned by the Get functions above.
    static void DestroyQtRakPeer( QtRakPeer* i );

};

#endif // QTRAKEXPORTFACTORY_H
