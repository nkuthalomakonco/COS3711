#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"


class StudentRegistration: public Registration
{
    Q_OBJECT
    Q_PROPERTY(QString qualification READ Qualification WRITE setQualification)
public:
    StudentRegistration(Person p, QString q);
    double calculateFee();
    QString toString();
    QString Qualification() const;
    void setQualification(const QString &newQualification);

private:
    QString m_Qualification;
};

#endif // STUDENTREGISTRATION_H
