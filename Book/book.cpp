#include "book.h"

Book::Book()
:title("title"),isbn("isbn")
{

}

Book::Book(QString t, QStringList a, QString i, QDate d)
    :title(t),authors(a),isbn(i),publicationDate(d)
{

}

Book::~Book()
{

}

QString Book::toString() const
{
    return QString("title: "+ title +"authors: " + authors.join(",") +
                   "isbn: " + isbn + "publicationDate: " + publicationDate.toString());
}
