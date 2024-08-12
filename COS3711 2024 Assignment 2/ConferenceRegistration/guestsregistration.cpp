#include "guestsregistration.h"


GuestsRegistration::GuestsRegistration(Person p, QString c)
    :Registration(p),m_Catergory(c)
{

}

double GuestsRegistration::calculateFee()
{
    return Registration::calculateFee() - (Registration::calculateFee() * 0.1);
}

QString GuestsRegistration::toString()
{
    Person p = getAttendee();
    return QString("Reg Attendee[guests]: %1 Booking date: %2 Fee: R%3 Catergory: %4")
        .arg(p.toString(),getBookingDate().toString("yyyy-MM-dd"),QString::number(calculateFee(), 'f', 3),m_Catergory);
}

QString GuestsRegistration::Catergory() const
{
    return m_Catergory;
}

void GuestsRegistration::setCatergory(const QString &newCatergory)
{
    m_Catergory = newCatergory;
}
