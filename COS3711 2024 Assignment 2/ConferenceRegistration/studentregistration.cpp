#include "studentregistration.h"


StudentRegistration::StudentRegistration(Person p, QString q)
    :Registration(p),m_Qualification(q)
{

}

double StudentRegistration::calculateFee()
{
    return Registration::calculateFee() / 2;
}

QString StudentRegistration::toString()
{
    //return QString("");

    Person p = getAttendee();
    return QString("Reg Attendee[student]: %1 Booking date: %2 Fee: R%3 Qualification: %4")
        .arg(p.toString(),getBookingDate().toString("yyyy-MM-dd"),QString::number(calculateFee(), 'f', 3),m_Qualification);
}

QString StudentRegistration::Qualification() const
{
    return m_Qualification;
}

void StudentRegistration::setQualification(const QString &newQualification)
{
    m_Qualification = newQualification;
}
