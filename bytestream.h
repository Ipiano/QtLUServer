#ifndef BYTESTREAM_H
#define BYTESTREAM_H

#include <QtGlobal>
#include <QByteArray>
#include <QString>

class ByteStream
{
    QByteArray::iterator curr;
    QByteArray::iterator end;
    quint64 space;

    void expand(quint64 add)
    {
        data.resize(data.size() + add);
        end = data.end();
        space += add;
        curr = data.begin() + data.size()-space;
    }

public:
    QByteArray data;

    ByteStream(quint64 size = 0)
    {
        space = size;
        data.resize(size);
        curr = data.begin();
        end = data.end();
    }

    ByteStream(const QByteArray& _data)
    {
        space = _data.size();
        data = _data;
        curr = data.begin();
        end = data.end();
    }

    void skip(quint64 bytes)
    {
        if(space < bytes)
            expand(bytes-space);
        curr += bytes;
        space -= bytes;
    }

    quint64 remaining(){return space;}

    template <class T>
    T readNumber()
    {
        quint64 buff = 0;
        for(int i=0, shift = 0; i<sizeof(T); i++, curr++, shift+=8)
        {
            buff |= ((*curr) << shift);
        }

        space -= sizeof(T);
        return *((T*)(&buff));
    }

    template <class T>
    void writeNumber(T number)
    {
        if(space < sizeof(T))
            expand(sizeof(T) - space);

        for(int i=0; i<sizeof(T); i++, curr++, number>>=8)
        {
            *curr = number&0xFF;
        }

        space -= sizeof(T);
    }

    QString readString(quint32 len)
    {
        QByteArray out;
        if(len > 0)
        {
            out.resize(len);
            for(auto& c : out)
                c = *(curr++);
        }
        else
        {
            do
            {
                out.push_back(*curr);
            }while(*(curr++) != 0);
        }

        space -= len;
        return out;
    }

    void writeString(QString str, qint32 len)
    {
        if(space < len)
            expand(len - space);

        str = str.left(len);

        for(const auto& c : str.toLatin1())
        {
            writeNumber<quint8>(c);
        }

        len -= str.size();

        while(len-- > 0)
            writeNumber<quint8>(0);
    }

    QString readWString(qint32 len)
    {
        wchar_t* arr = new wchar_t[len];
        wchar_t* iter = arr;

        for(int i=0; i<len; i++, iter++)
        {
            *iter = readNumber<wchar_t>();
        }

        QString out = QString::fromWCharArray(arr);
        delete[] arr;

        space -= len*sizeof(wchar_t);
        return out;
    }

    void writeWString(QString str, quint32 len)
    {
        int bytes = len * sizeof(wchar_t);
        if(space < bytes) expand(bytes - space);

        str = str.left(len);

        wchar_t* arr = new wchar_t[str.size()];
        wchar_t* iter = arr;
        str.toWCharArray(arr);

        for(int i=0; i<str.size(); i++, iter++)
            writeNumber(*iter);

        len -= str.size();

        while(len-- > 0)
            writeNumber<wchar_t>(0);

        delete[] arr;
    }
};

#endif // BYTESTREAM_H
