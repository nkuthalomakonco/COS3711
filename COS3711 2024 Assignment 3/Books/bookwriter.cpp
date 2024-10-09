#include "bookwriter.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

BookWriter::BookWriter(QString fn)
{
    fileName = fn;
}

bool BookWriter::write(const Book &b)
{
    QFile file(fileName);
    if (!file.open(QIODevice::Append))
    {
        return false;
    }
    QTextStream out(&file);    
    QString authors = b.getAuthors().join(", ");
    QString bookState = QString("%1: %2: %3: %4\n").arg(b.getTitle()).arg(authors).arg(b.getIsbn()).arg(b.getPublicationDate().toString());
    out << bookState;
    file.close();
    return true;
}




