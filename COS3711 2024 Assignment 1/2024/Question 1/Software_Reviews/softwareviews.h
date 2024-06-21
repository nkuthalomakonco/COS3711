#ifndef SOFTWAREVIEWS_H
#define SOFTWAREVIEWS_H

#include <QDate>

class softwareviews
{
public:
    softwareviews();
    softwareviews(QString,QDate,bool);
    ~softwareviews();
    QString toString()const;

    QString getName() const;
    void setName(const QString &newName);

    QDate getDate() const;
    void setDate(const QDate &newDate);

private:
    QString name;//software name.
    QDate date;//software date.
    bool recommended;//recommended yes/no true/false.
};

#endif // SOFTWAREVIEWS_H
