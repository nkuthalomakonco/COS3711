#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include <QString>

class TableModel;

class RegistrationListWriter
{
public:
    RegistrationListWriter(TableModel *model);
    bool write(QString fileName = "registration.xml");

private:
    TableModel *rtm;
};

#endif // REGISTRATIONLISTWRITER_H
