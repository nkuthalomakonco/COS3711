#ifndef BOOK_H
#define BOOK_H

#include <QStringList>
#include <QDate>

class Book
{
public:
    //constructors
    Book();
    Book(QString t, QStringList a, QString i, QDate d);
    //setters
    void setTitle(QString t);
    void setAuthors(QStringList a);
    void setIsbn(QString i);
    void setPublicationDate(QDate d);
    //getters
    QString getTitle() const;
    QStringList getAuthors()const;
    QString getIsbn() const;
    QDate getPublicationDate() const;
private:
    //data members
    QString title;
    QStringList authors;
    QString isbn;
    QDate publicationDate;
};

#endif // BOOK_H
