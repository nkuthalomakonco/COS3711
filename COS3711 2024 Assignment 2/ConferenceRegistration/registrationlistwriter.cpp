#include "registrationlistwriter.h"
#include "tablemodel.h"
#include "filewriter.h"

#include "registration.h"

#include <QDomDocument>
#include <QMetaProperty>

RegistrationListWriter::RegistrationListWriter(TableModel *model):rtm(model)
{

}

bool RegistrationListWriter::write(QString fileName)
{

    // Check if there are rows in the model
    int numRows = rtm->rowCount(QModelIndex());

    if (numRows == 0) {
        return false;
    }

    QDomDocument doc;
    QDomElement root(doc.createElement("registrationlist"));
    doc.appendChild(root);
    const  QList<Registration*> list = rtm->getList();

    // Using QMetaObject
    const QMetaObject *meta;
    int numProperties;
    QMetaProperty metaProp;
    QString classname;

    foreach(auto *reg, list){
        meta = reg->metaObject();
        numProperties = meta->propertyCount();
        classname = QString::fromLatin1(reg->metaObject()->className());
        QDomElement rootregistration = doc.createElement("registration");
        rootregistration.setAttribute("type", classname);
        root.appendChild(rootregistration);
        QDomElement rootattendee = doc.createElement("attendee");
        rootregistration.appendChild(rootattendee);
        // Start from 1, omit objectName property
        for (int count = 1; count < numProperties; count++) {
            metaProp = meta->property(count);
            const char *name = metaProp.name();
            QVariant value = reg->property(name);
            //person is not an qobject.
            if(QString(name) == "person"){
                //auto * p = qobject_cast<Person*>(reg);
                const auto p = reg->getAttendee();
                QDomElement element = doc.createElement("name");
                QDomText text = doc.createTextNode(p.getName());
                element.appendChild(text);
                rootattendee.appendChild(element);
                element = doc.createElement("affiliation");
                text = doc.createTextNode(p.getAffiliation());
                element.appendChild(text);
                rootattendee.appendChild(element);
                element = doc.createElement("email");
                text = doc.createTextNode(p.getEmail());
                element.appendChild(text);
                rootattendee.appendChild(element);
            }else{
                QDomElement element = doc.createElement(name);
                QDomText text = doc.createTextNode(value.toString());

                element.appendChild(text);
                rootattendee.appendChild(element);
            }

        }
    }

    for (int row = 0; row < numRows; row++) {

//        QDomElement reg(doc.createElement("Registration"));
//        QString className = rtm->getList().at(row)->metaObject()->className();
//        reg.setAttribute("type", className);
//        root.appendChild(reg);

//        Registration *obj = rtm->getList().at(row);
//        const QMetaObject* metaObject = obj->metaObject();
//        QString classname = QString::fromLatin1(obj->metaObject()->className());

    }

    QString out = doc.toString();

    FileWriter fw(fileName);
    if (!fw.write(out)) {
        qDebug()<<"";
        return false;
    }

    return true;
}
