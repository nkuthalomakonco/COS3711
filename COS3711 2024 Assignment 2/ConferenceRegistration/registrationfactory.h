#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H

#include <QString>

class Registration;
//class Person;

class RegistrationFactory
{
public:
    static RegistrationFactory* getInstance();
    Registration* createRegistration(QString type,
                             QString name,
                             QString email,
                             QString affiliation,
                             QString catergory = QString(),
                             QString qualification = QString());

    // Registration* createStandardRegistration(QString name,QString affiliation,QString email);
    // Registration* createStudentRegistration(QString name,QString affiliation,QString email,QString qualification);
    // Registration* createGuestsRegistration(QString name,QString affiliation,QString email,QString catergory);

    // Registration* createStandardRegistration(Person p);
    // Registration* createStudentRegistration(Person p,QString qualification);
    // Registration* createGuestsRegistration(Person p,QString email,QString catergory);

private:
    RegistrationFactory();
    static RegistrationFactory* onlyInstance;
};

#endif // REGISTRATIONFACTORY_H
