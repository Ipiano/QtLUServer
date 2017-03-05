#ifndef CONSOLEREADERTHREAD_H
#define CONSOLEREADERTHREAD_H

#include <QString>
#include <QObject>
#include <QTextStream>
#include <QMutex>
#include <QMutexLocker>
#include <QtConcurrent/QtConcurrent>

class ConsoleReaderWorker : public QObject
{
    Q_OBJECT

public slots:
    void readLine();

signals:
    void gotLine(QString);
};

class ConsoleReader : public QObject
{
    Q_OBJECT

    ConsoleReaderWorker _worker;
    QThread _reader;
    bool _running = true;
    bool _handling = false;
    bool _reading = false;

public:
    ConsoleReader(QObject* parent=NULL);
    ~ConsoleReader();

    void start()
    {
        if(_reading) return;

        _running = true;
        _reading = true;
        emit readingLine();
    }

    bool stop()
    {
        if(!_handling) return false;

        _running = false;
        return true;
    }

private slots:
    void lineReady(QString line);

signals:
    void gotLine(QString);
    void readingLine();
};

#endif // CONSOLEREADERTHREAD_H
