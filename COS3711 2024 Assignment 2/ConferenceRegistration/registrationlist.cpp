#include "registrationlist.h"

//RegistrationList::RegistrationList()
//: m_AttendeeList(new QList<Registration*>)
//{

//}

//RegistrationList::~RegistrationList()
//{
//    clear();
//    delete m_AttendeeList;
//}

//void RegistrationList::addRegistration(Registration *reg)
//{
//    if (reg == NULL ) return;
//    m_AttendeeList->append(reg);
//}

//bool RegistrationList::isRegistered(Registration reg)
//{
//    return m_AttendeeList->contains(&reg) ? true : false;
//}

//double RegistrationList::totalFee(QString type)
//{
//    return 1;
//}

//int RegistrationList::totalRegistration(QString type) const
//{
//    if (m_AttendeeList == 0 ) return 0;
//    return m_AttendeeList->size();
//}

//int RegistrationList::size() const
//{
//    if (m_AttendeeList == 0 ) return 0;
//    return m_AttendeeList->size();
//}

//void RegistrationList::clear()
//{
//    m_AttendeeList->clear();
//}

//bool RegistrationList::contains(Registration reg)
//{
//    return 0;
//    return m_AttendeeList->contains(&reg) ? 1 : 0;
//}

//QList<Registration *> *RegistrationList::getList() const
//{
//    if (m_AttendeeList == 0 ) return 0;
//    return m_AttendeeList;
//}


//Registration *RegistrationList::getRegistration(int position) const
//{
//    if (m_AttendeeList == 0 ) return 0;
//    if (m_AttendeeList->empty() ) return 0;
//    return m_AttendeeList->at(position);
//}

//void RegistrationList::setRegistration(int position, Registration *registration)
//{
//    m_AttendeeList->replace(position,registration);
//}

//QString RegistrationList::toString() const
//{
//    return QString();
//}
