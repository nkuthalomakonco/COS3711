#include "registration.h"


Registration::Registration(Person p): m_Attendee(p)
{
    m_BookingDate = QDate::currentDate();
    STANDARD_FEE = fee;
}

double Registration::calculateFee()
{
    return STANDARD_FEE;
}

Person Registration::getAttendee() const
{
    return m_Attendee;
}

QDate Registration::getBookingDate()
{
    return m_BookingDate;
}

QString Registration::toString() const
{
    return QString("Reg Attendee[stardand]: %1 Booking date: %2 Fee: R%3")
        .arg(m_Attendee.toString(),m_BookingDate.toString("yyyy-MM-dd"),QString::number(STANDARD_FEE, 'f', 3));
}

void Registration::setSTANDARD_FEE(double newSTANDARD_FEE)
{
    STANDARD_FEE = newSTANDARD_FEE;
}

void Registration::setBookingDate(const QDate &newBookingDate)
{
    m_BookingDate = newBookingDate;
}

void Registration::setAttendee(const Person &newAttendee)
{
    m_Attendee = newAttendee;
}

bool Registration::operator==(const Registration &other) const
{
   return m_Attendee.getName() == other.getAttendee().getName() && m_Attendee.getEmail() == other.getAttendee().getEmail();
}
