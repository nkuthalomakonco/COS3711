#include "book.h"

Book::Book()
{
    QString defaultValue = "Unknown";
    title = defaultValue;
    authors << defaultValue;
    isbn = defaultValue;
}

Book::Book(QString t, QStringList a, QString i, QDate d)
{
    title = t;
    authors = a;
    isbn = i;
    publicationDate = d;
}

void Book::setTitle(QString t)
{
    title = t;
}

void Book::setAuthors(QStringList a)
{
    authors = a;
}

void Book::setIsbn(QString i)
{
    isbn = i;
}

void Book::setPublicationDate(QDate d)
{
    publicationDate = d;
}

QString Book::getTitle() const
{
    return title;
}

QStringList Book::getAuthors() const
{
    return authors;
}

QString Book::getIsbn() const
{
    return isbn;
}

QDate Book::getPublicationDate() const
{
    return publicationDate;
}
