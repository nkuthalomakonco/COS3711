#include "bookwriter.h"
#include <QFile>
#include <QTextStream>
#include <QMetaObject>
#include <QMetaProperty>

BookWriter::BookWriter(QString fn)
{
    fileName = fn;
}

bool BookWriter::write(const Book* b)
{
    QFile file(fileName);
    if (!file.open(QIODevice::Append))
    {
        return false;
    }
    QTextStream out(&file);

    const QMetaObject *meta = b->metaObject();
    int totalProperties = meta->propertyCount();

    QStringList bookState;
    QString temp;

    for(int i =1; i <totalProperties; i++)
    {
        QMetaProperty prop = meta->property(i);
        if(prop.typeId()==QMetaType::QStringList)
        {
           temp = prop.read(b).toStringList().join(", ");
        }
        else
        {
           temp = prop.read(b).toString();
        }
        bookState.append(temp);
    }

    out<<bookState.join(": ") << "\n";
    file.close();
    return true;
}

