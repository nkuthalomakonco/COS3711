#ifndef PERSON_H
#define PERSON_H

#include <QString>
//#include <QObject>

//class Person:public QObject
class Person
{
//    Q_OBJECT
//    Q_PROPERTY(QString name READ getName WRITE setName)
//    Q_PROPERTY(QString affiliation READ getAffiliation WRITE setAffiliation)
//    Q_PROPERTY(QString email READ getEmail WRITE setEmail)
public:
    Person();
    Person(QString name,QString affiliation,QString email);
    QString toString() const;
    QString getName() const;
    void setName(const QString &newName);

    QString getAffiliation() const;
    void setAffiliation(const QString &newAffiliation);

    QString getEmail() const;
    void setEmail(const QString &newEmail);

private:
    QString m_Name;
    QString m_Affiliation;
    QString m_Email;
};

#endif // PERSON_H
