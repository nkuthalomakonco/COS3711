#include "person.h"


Person::Person()
: m_Name("name"),m_Affiliation("affiliation"),m_Email("email")
{

}

Person::Person(QString name, QString affiliation, QString email)
    : m_Name(name),m_Affiliation(affiliation),m_Email(email)
{

}

QString Person::toString() const
{
    return QString("Name: %1 Affiliation: %2 Email: %3")
        .arg(this->m_Name,this->m_Affiliation,this->m_Email);
}

QString Person::getName() const
{
    return m_Name;
}

void Person::setName(const QString &newName)
{
    m_Name = newName;
}

QString Person::getAffiliation() const
{
    return m_Affiliation;
}

void Person::setAffiliation(const QString &newAffiliation)
{
    m_Affiliation = newAffiliation;
}

QString Person::getEmail() const
{
    return m_Email;
}

void Person::setEmail(const QString &newEmail)
{
    m_Email = newEmail;
}

