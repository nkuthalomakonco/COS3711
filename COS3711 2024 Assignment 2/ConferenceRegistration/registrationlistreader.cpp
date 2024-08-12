#include "registrationlistreader.h"
#include "registration.h"
#include "guestsregistration.h"
#include "studentregistration.h"
#include "registrationfactory.h"

#include <QXmlStreamReader>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

RegistrationListReader::RegistrationListReader()
{

}

QList<Registration *> RegistrationListReader::read(QString fileName)
{
    // Instantiate list and
    QList<Registration*> reg;

    QTextStream cout(stdout);

    // Open file
    QFile inFile(fileName);
    if (!inFile.open(QIODevice::ReadOnly)) {
        // Return empty list
        cout << "Cannot open file: " << fileName << Qt::endl;
        return reg;
    }

    // Declare reader, and set file
    QXmlStreamReader reader(&inFile);

    //

    QList<QStringList> data;
    QStringList registrationDetails;
    bool collect = false;

    // Check if the file is a list of registrationlist
    reader.readNextStartElement();
    if (reader.name().toString() == "registrationlist") {
        while (!reader.atEnd())
        {
            QXmlStreamReader::TokenType tt = reader.readNext();

            switch (tt)
            {
            case QXmlStreamReader::StartElement:
            {   //Registration or StudentRegistration or GuestsRegistration
                if (reader.name().toString()=="registration" || reader.name().toString()=="StudentRegistration" || reader.name().toString()=="GuestsRegistration"){
                    QXmlStreamAttributes attrs = reader.attributes();
                    registrationDetails << attrs.value("type").toString();
                }
                else if (reader.name().toString()=="attendee")
                {
                    collect=true;
                }
                break;
            }
            case QXmlStreamReader::Characters:
            {
                if (collect) {
                    QRegularExpression re("\\w+");//word.
                    QString text = reader.text().toString();
                    QRegularExpressionMatch match = re.match(text);
                    bool hasMatch = match.hasMatch(); // true
                    if(hasMatch)registrationDetails << text;}
                break;
            }
            case QXmlStreamReader::EndElement:
            {
                if (reader.name().toString()=="attendee")
                {
                    collect=false;
                    if(createRegistration(registrationDetails) != 0)reg.append(createRegistration(registrationDetails));
                    registrationDetails.clear();
                }
                break;
            }
            default:
                break;
            }

            if (reader.hasError())
            {
                qDebug() << "XML error: " << reader.errorString();
                reg.clear();
                return  reg;
            }
        }//end while.
    }//end if.

    inFile.close();

    //recreate objects
    if (!data.isEmpty()){
//        foreach (const auto d, data) {
//            //foreach(const auto stri, registrationDetails)qDebug()<< stri;
//            QString type = d.at(0);
//            Person p(d.at(1),d.at(2),d.at(3));
//            if(type == "Registration")
//            {
//                Registration *r = new Registration(p);
//                r->setBookingDate(QDate::fromString(d.at(4)));
//                //r->setSTANDARD_FEE(d.at(4).toDouble());
//                reg.append(r);
//                qDebug()<< r->toString();
//            }
//            else if(type == "StudentRegistration"){
//                QString q = d.at(4);
//                StudentRegistration *r = new StudentRegistration(p,q);
//                r->setBookingDate(QDate::fromString(d.at(4)));
//                reg.append(r);
//                qDebug()<< r->toString();
//            }else if(type == "GuestsRegistration"){
//                QString c = d.at(4);
//                GuestsRegistration *r = new GuestsRegistration(p,c);
//                r->setBookingDate(QDate::fromString(d.at(4)));
//                reg.append(r);
//                qDebug()<< r->toString();
//            }else{}

//        }
    }

    return reg;
}
//recreate Registration object.
Registration *RegistrationListReader::createRegistration(QStringList d) const
{
    QString type = d.at(0);
    Person p(d.at(1),d.at(2),d.at(3));
    QDate date = QDate::fromString(d.at(4),"yyyy-MM-dd");
    double fee = d.at(5).toDouble();//is calculated.
    QString catergory = "";
    QString qualification = "";

    if (d.size() == 7){
         catergory = d.at(6);
         qualification = d.at(6);
    }
    (void)fee;
//    if(type == "Registration")
//    {
//        Registration *r = new Registration(p);
//        r->setBookingDate(date);

//        qDebug()<< r->toString();return r;
//    }
//    else if(type == "StudentRegistration"){
//        QString q = d.at(6);
//        StudentRegistration *r = new StudentRegistration(p,q);
//        r->setBookingDate(date);

//        qDebug()<< r->toString();return r;
//    }else if(type == "GuestsRegistration"){
//        QString c = d.at(6);
//        GuestsRegistration *r = new GuestsRegistration(p,c);
//        r->setBookingDate(date);

//        qDebug()<< r->toString();return r;
//    }else{}
    //RegistrationFactory.
        if(type == "Registration") {
        type = "standard";
        }
        else if(type == "StudentRegistration"){
            type = "student";
        }else if(type == "GuestsRegistration"){
            type = "guest";
        }else{}

        //Implement a factory class (RegistrationFactory)
        //Make the RegistrationFactory an implementation of the Singleton pattern.
        RegistrationFactory rf = *RegistrationFactory::getInstance();
;

        Registration *r = rf.createRegistration(type,p.getName(),p.getEmail(),p.getAffiliation(),catergory,qualification);
        r->setBookingDate(date);
        return r;

    return 0;
}
