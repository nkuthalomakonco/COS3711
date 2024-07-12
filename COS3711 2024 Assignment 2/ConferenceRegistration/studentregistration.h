#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"


class StudentRegistration: public Registration
{
    Q_OBJECT
    Q_PROPERTY(QString qualification READ Qualification WRITE setQualification)
public:


private:
    QString m_Qualification;
};

#endif // STUDENTREGISTRATION_H
