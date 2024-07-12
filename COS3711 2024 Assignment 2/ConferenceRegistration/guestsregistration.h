#ifndef GUESTSREGISTRATION_H
#define GUESTSREGISTRATION_H

#include "registration.h"

class GuestsRegistration: public Registration
{
    Q_OBJECT
    Q_PROPERTY(QString catergory READ Catergory WRITE setCatergory)
public:
    GuestsRegistration(Person p, QString c);
    double calculateFee();
    QString toString();
    QString Catergory() const;
    void setCatergory(const QString &newCatergory);

private:
    QString m_Catergory;

};

#endif // GUESTSREGISTRATION_H
