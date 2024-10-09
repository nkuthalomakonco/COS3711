#ifndef BOOK_H
#define BOOK_H

#include <QStringList>
#include <QDate>

class Book : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(QStringList authors READ getAuthors WRITE setAuthors)
    Q_PROPERTY(QString isbn READ getIsbn WRITE setIsbn)
    Q_PROPERTY(QDate publicationDate READ getPublicationDate WRITE setPublicationDate)
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
