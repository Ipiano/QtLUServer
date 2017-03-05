#include "ConsoleReaderThread.h"

#include <QDebug>

void ConsoleReaderWorker::readLine()
{
    QTextStream cin(stdin);
    emit gotLine(cin.readLine());
}

ConsoleReader::ConsoleReader(QObject* parent) : QObject(parent)
{
    _worker.moveToThread(&_reader);
    _reader.start();

    connect(&_worker, &ConsoleReaderWorker::gotLine, this, &ConsoleReader::lineReady, Qt::QueuedConnection);
    connect(this, &ConsoleReader::readingLine, &_worker, &ConsoleReaderWorker::readLine);
}

ConsoleReader::~ConsoleReader()
{
    _reader.exit();
    _reader.wait();
}

void ConsoleReader::lineReady(QString line)
{
    _reading = false;
    _handling = true;
    emit gotLine(line);
    _handling = false;
    if(_running)
        start();
}
