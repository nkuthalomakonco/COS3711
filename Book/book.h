#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QDate>

class Book
{
    Book();
    Book(QString t, QStringList a,QString i,QDate d);
    ~Book();
    QString toString()const;

private:
    QString title;
    QStringList authors;
    QString isbn;
    QDate publicationDate;
};

#endif // BOOK_H
