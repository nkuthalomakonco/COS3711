#include "softwareviews.h"


softwareviews::softwareviews()
{

}

softwareviews::softwareviews(QString n, QDate d, bool r)
    :name(n),date(d),recommended(r)
{
}

softwareviews::~softwareviews()
{

}

QString softwareviews::toString() const
{
    QString date_ = date.toString("dd/MM/yyyy");
    QString recommend = "No";
    if(recommended)
        recommend = "Yes";

    return QString("Name: %1 Date: %2 Recommended: %3")
        .arg(name,date_,recommend);
}

QString softwareviews::getName() const
{
    return name;
}

void softwareviews::setName(const QString &newName)
{
    name = newName;
}

QDate softwareviews::getDate() const
{
    return date;
}

void softwareviews::setDate(const QDate &newDate)
{
    date = newDate;
}

bool softwareviews::getRecommended() const
{
    return recommended;
}

void softwareviews::setRecommended(bool newRecommended)
{
    recommended = newRecommended;
}
