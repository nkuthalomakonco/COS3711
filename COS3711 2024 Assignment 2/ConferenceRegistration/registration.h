#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"

#include <QString>
#include <QDate>
#include <QObject>

const double fee = 100;

class Registration: public QObject
{
    Q_OBJECT
    Q_PROPERTY(Person person READ getAttendee WRITE setAttendee NOTIFY propertyChanged)
    Q_PROPERTY(QDate date READ getBookingDate WRITE setBookingDate)
    Q_PROPERTY(double fee READ calculateFee WRITE setSTANDARD_FEE)

signals:
    void propertyChanged();
public:
    Registration(Person p);
    virtual double calculateFee();
    Person getAttendee()const;
    QDate getBookingDate();
    QString toString() const;

    void setSTANDARD_FEE(double newSTANDARD_FEE);
    void setBookingDate(const QDate &newBookingDate);
    void setAttendee(const Person &newAttendee);

    bool operator==(const Registration &other) const;

public:
    double STANDARD_FEE;
private:
    QDate m_BookingDate;
    Person m_Attendee;
};

#endif // REGISTRATION_H
