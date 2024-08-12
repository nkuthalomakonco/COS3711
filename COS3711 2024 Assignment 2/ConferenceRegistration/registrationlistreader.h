#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H


#include <QString>
class Registration;

class RegistrationListReader
{
public:
    RegistrationListReader();
    QList<Registration*> read(QString fileName = "registration.xml") ;
private:
    Registration *createRegistration(QStringList data)const;
};

#endif // REGISTRATIONLISTREADER_H
