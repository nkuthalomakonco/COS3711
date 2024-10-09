#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "book.h"

class BookWriter
{
public:
    BookWriter(QString fn);
    bool write(const Book& b);
private:
    QString fileName;
};

#endif // BOOKWRITER_H
