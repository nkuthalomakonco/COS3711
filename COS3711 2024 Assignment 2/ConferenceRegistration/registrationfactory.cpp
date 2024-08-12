#include "registrationfactory.h"

#include "registration.h"
#include "studentregistration.h"
#include "guestsregistration.h"

RegistrationFactory* RegistrationFactory::onlyInstance = NULL;

RegistrationFactory* RegistrationFactory::getInstance()
{
    if (onlyInstance == NULL)
        onlyInstance = new RegistrationFactory;
    return onlyInstance;
}

RegistrationFactory::RegistrationFactory()
{

}

Registration *RegistrationFactory::createRegistration(QString type, QString name, QString email, QString affiliation, QString catergory, QString qualification)
{
    if (type == "guest") {
        return new GuestsRegistration(Person(name,affiliation,email),catergory);
    }
    else if (type == "student") {
        return new StudentRegistration(Person(name,affiliation,email),qualification);
    }
    else if (type == "standard") {
        Person p(name, affiliation, email);
        return new Registration(p);
    }
    else {
        return nullptr;
    }
}

// Registration *RegistrationFactory::createStandardRegistration(QString name, QString affiliation, QString email)
// {
//     Person p(name, affiliation, email);
//     return new Registration(p);
// }

// Registration *RegistrationFactory::createStudentRegistration(QString name, QString affiliation, QString email, QString qualification)
// {
//  return new StudentRegistration(Person(name,affiliation,email),qualification);
// }

// Registration *RegistrationFactory::createGuestsRegistration(QString name, QString affiliation, QString email, QString catergory)
// {
//  return new GuestsRegistration(Person(name,affiliation,email),catergory);
//}
