#-------------------------------------------------
#
# Project created by QtCreator 2017-03-04T13:15:52
#
#-------------------------------------------------

QT       -= gui
QT       += core

TARGET = QtRakNet
TEMPLATE = lib
CONFIG += staticlib c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#PWD Breaks on my win10 if you have spaces in your path (which I do)
#But I have a symbolic link set up which has the same path, just with _ instead of the space
#I should probably just change my user to not have a space...
TMPPWD = $$replace(PWD," ","_")

include(qtraknet.pri)

CONFIG(debug, debug|release){
    BUILD_DIR=$$TMPPWD/build/debug
    isEmpty(LIB_DIR):LIB_DIR=$$TMPPWD/lib/debug
    TARGET=$$join(TARGET,,,_d)
}else{
    BUILD_DIR=$$TMPPWD/build/release
    isEmpty(LIB_DIR):LIB_DIR=$$TMPPWD/lib/release
}

MOC_DIR = $$LIB_DIR/.moc
OBJECTS_DIR = $$LIB_DIR
DESTDIR = $$LIB_DIR

SOURCES += \
    RakNet3.25/_FindFirst.cpp \
    RakNet3.25/AsynchronousFileIO.cpp \
    RakNet3.25/AutoRPC.cpp \
    RakNet3.25/BitStream.cpp \
    RakNet3.25/BitStream_NoTemplate.cpp \
    RakNet3.25/CheckSum.cpp \
    RakNet3.25/CommandParserInterface.cpp \
    RakNet3.25/ConnectionGraph.cpp \
    RakNet3.25/ConsoleServer.cpp \
    RakNet3.25/DataBlockEncryptor.cpp \
    RakNet3.25/DataCompressor.cpp \
    RakNet3.25/DirectoryDeltaTransfer.cpp \
    RakNet3.25/DS_BytePool.cpp \
    RakNet3.25/DS_ByteQueue.cpp \
    RakNet3.25/DS_HuffmanEncodingTree.cpp \
    RakNet3.25/DS_Table.cpp \
    RakNet3.25/EmailSender.cpp \
    RakNet3.25/EncodeClassName.cpp \
    RakNet3.25/EpochTimeToString.cpp \
    RakNet3.25/ExtendedOverlappedPool.cpp \
    RakNet3.25/FileList.cpp \
    RakNet3.25/FileListTransfer.cpp \
    RakNet3.25/FileOperations.cpp \
    RakNet3.25/FormatString.cpp \
    RakNet3.25/FullyConnectedMesh.cpp \
    RakNet3.25/FunctionThread.cpp \
    RakNet3.25/Gen_RPC8.cpp \
    RakNet3.25/GetTime.cpp \
    RakNet3.25/GridSectorizer.cpp \
    RakNet3.25/HTTPConnection.cpp \
    RakNet3.25/InlineFunctor.cpp \
    RakNet3.25/Itoa.cpp \
    RakNet3.25/LightweightDatabaseClient.cpp \
    RakNet3.25/LightweightDatabaseCommon.cpp \
    RakNet3.25/LightweightDatabaseServer.cpp \
    RakNet3.25/LinuxStrings.cpp \
    RakNet3.25/LogCommandParser.cpp \
    RakNet3.25/MessageFilter.cpp \
    RakNet3.25/NatPunchthrough.cpp \
    RakNet3.25/NetworkIDManager.cpp \
    RakNet3.25/NetworkIDObject.cpp \
    RakNet3.25/PacketConsoleLogger.cpp \
    RakNet3.25/PacketFileLogger.cpp \
    RakNet3.25/PacketLogger.cpp \
    RakNet3.25/PluginInterface.cpp \
    RakNet3.25/RakMemoryOverride.cpp \
    RakNet3.25/RakNetCommandParser.cpp \
    RakNet3.25/RakNetStatistics.cpp \
    RakNet3.25/RakNetTransport.cpp \
    RakNet3.25/RakNetTypes.cpp \
    RakNet3.25/RakNetworkFactory.cpp \
    RakNet3.25/RakPeer.cpp \
    RakNet3.25/RakSleep.cpp \
    RakNet3.25/RakString.cpp \
    RakNet3.25/RakThread.cpp \
    RakNet3.25/Rand.cpp \
    RakNet3.25/ReadyEvent.cpp \
    RakNet3.25/ReliabilityLayer.cpp \
    RakNet3.25/ReplicaManager.cpp \
    RakNet3.25/ReplicaManager2.cpp \
    RakNet3.25/rijndael.cpp \
    RakNet3.25/Router.cpp \
    RakNet3.25/RPCMap.cpp \
    RakNet3.25/SHA1.cpp \
    RakNet3.25/SimpleMutex.cpp \
    RakNet3.25/SocketLayer.cpp \
    RakNet3.25/StringCompressor.cpp \
    RakNet3.25/StringTable.cpp \
    RakNet3.25/SuperFastHash.cpp \
    RakNet3.25/SystemAddressList.cpp \
    RakNet3.25/TableSerializer.cpp \
    RakNet3.25/TCPInterface.cpp \
    RakNet3.25/TelnetTransport.cpp \
    RakNet3.25/ThreadsafePacketLogger.cpp \
    QtRakNetworkFactory.cpp \
    QtRakPeer.cpp

HEADERS += \
    RakNet3.25/_FindFirst.h \
    RakNet3.25/AsynchronousFileIO.h \
    RakNet3.25/AutopatcherPatchContext.h \
    RakNet3.25/AutopatcherRepositoryInterface.h \
    RakNet3.25/AutoRPC.h \
    RakNet3.25/BigTypes.h \
    RakNet3.25/BitStream.h \
    RakNet3.25/BitStream_NoTemplate.h \
    RakNet3.25/CheckSum.h \
    RakNet3.25/ClientContextStruct.h \
    RakNet3.25/CommandParserInterface.h \
    RakNet3.25/ConnectionGraph.h \
    RakNet3.25/ConsoleServer.h \
    RakNet3.25/DataBlockEncryptor.h \
    RakNet3.25/DataCompressor.h \
    RakNet3.25/DirectoryDeltaTransfer.h \
    RakNet3.25/DS_BinarySearchTree.h \
    RakNet3.25/DS_BPlusTree.h \
    RakNet3.25/DS_BytePool.h \
    RakNet3.25/DS_ByteQueue.h \
    RakNet3.25/DS_Heap.h \
    RakNet3.25/DS_HuffmanEncodingTree.h \
    RakNet3.25/DS_HuffmanEncodingTreeFactory.h \
    RakNet3.25/DS_HuffmanEncodingTreeNode.h \
    RakNet3.25/DS_LinkedList.h \
    RakNet3.25/DS_List.h \
    RakNet3.25/DS_Map.h \
    RakNet3.25/DS_MemoryPool.h \
    RakNet3.25/DS_OrderedChannelHeap.h \
    RakNet3.25/DS_OrderedList.h \
    RakNet3.25/DS_Queue.h \
    RakNet3.25/DS_QueueLinkedList.h \
    RakNet3.25/DS_RangeList.h \
    RakNet3.25/DS_Table.h \
    RakNet3.25/DS_Tree.h \
    RakNet3.25/DS_WeightedGraph.h \
    RakNet3.25/EmailSender.h \
    RakNet3.25/EpochTimeToString.h \
    RakNet3.25/Export.h \
    RakNet3.25/ExtendedOverlappedPool.h \
    RakNet3.25/FileList.h \
    RakNet3.25/FileListTransfer.h \
    RakNet3.25/FileListTransferCBInterface.h \
    RakNet3.25/FileOperations.h \
    RakNet3.25/FormatString.h \
    RakNet3.25/FullyConnectedMesh.h \
    RakNet3.25/FunctionThread.h \
    RakNet3.25/Gen_RPC8.h \
    RakNet3.25/GetTime.h \
    RakNet3.25/GridSectorizer.h \
    RakNet3.25/HTTPConnection.h \
    RakNet3.25/InlineFunctor.h \
    RakNet3.25/InternalPacket.h \
    RakNet3.25/Itoa.h \
    RakNet3.25/Kbhit.h \
    RakNet3.25/LightweightDatabaseClient.h \
    RakNet3.25/LightweightDatabaseCommon.h \
    RakNet3.25/LightweightDatabaseServer.h \
    RakNet3.25/LinuxStrings.h \
    RakNet3.25/LogCommandParser.h \
    RakNet3.25/MessageFilter.h \
    RakNet3.25/MessageIdentifiers.h \
    RakNet3.25/MTUSize.h \
    RakNet3.25/NatPunchthrough.h \
    RakNet3.25/NetworkIDManager.h \
    RakNet3.25/NetworkIDObject.h \
    RakNet3.25/PacketConsoleLogger.h \
    RakNet3.25/PacketFileLogger.h \
    RakNet3.25/PacketLogger.h \
    RakNet3.25/PacketPool.h \
    RakNet3.25/PacketPriority.h \
    RakNet3.25/PluginInterface.h \
    RakNet3.25/RakAssert.h \
    RakNet3.25/RakMemoryOverride.h \
    RakNet3.25/RakNetCommandParser.h \
    RakNet3.25/RakNetDefines.h \
    RakNet3.25/RakNetStatistics.h \
    RakNet3.25/RakNetTransport.h \
    RakNet3.25/RakNetTypes.h \
    RakNet3.25/RakNetVersion.h \
    RakNet3.25/RakNetworkFactory.h \
    RakNet3.25/RakPeer.h \
    RakNet3.25/RakPeerInterface.h \
    RakNet3.25/RakSleep.h \
    RakNet3.25/RakString.h \
    RakNet3.25/RakThread.h \
    RakNet3.25/Rand.h \
    RakNet3.25/ReadyEvent.h \
    RakNet3.25/RefCountedObj.h \
    RakNet3.25/ReliabilityLayer.h \
    RakNet3.25/Replica.h \
    RakNet3.25/ReplicaEnums.h \
    RakNet3.25/ReplicaManager.h \
    RakNet3.25/ReplicaManager2.h \
    RakNet3.25/Rijndael.h \
    RakNet3.25/Rijndael-Boxes.h \
    RakNet3.25/Router.h \
    RakNet3.25/RouterInterface.h \
    RakNet3.25/RPCMap.h \
    RakNet3.25/RPCNode.h \
    RakNet3.25/RSACrypt.h \
    RakNet3.25/SHA1.h \
    RakNet3.25/SimpleMutex.h \
    RakNet3.25/SimpleTCPServer.h \
    RakNet3.25/SingleProducerConsumer.h \
    RakNet3.25/SocketLayer.h \
    RakNet3.25/StringCompressor.h \
    RakNet3.25/StringTable.h \
    RakNet3.25/SuperFastHash.h \
    RakNet3.25/SystemAddressList.h \
    RakNet3.25/TableSerializer.h \
    RakNet3.25/TCPInterface.h \
    RakNet3.25/TelnetTransport.h \
    RakNet3.25/ThreadPool.h \
    RakNet3.25/ThreadsafePacketLogger.h \
    RakNet3.25/TransportInterface.h \
    RakNet3.25/Types.h \
    QtRakNetworkFactory.h \
    QtRakPeer.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
