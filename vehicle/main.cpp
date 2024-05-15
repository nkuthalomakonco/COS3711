#include <QTextStream>
#include "passengervehicle.h"
#include "transportvehicle.h"
#include "vehiclelist.h"

int main()
{

    QTextStream out(stdout);

    VehicleList *vList = new VehicleList;
    //PassengerVehicle(v_model,int v_year,passengers,QObject *parent);
    new PassengerVehicle(QString("Mazda Soho"), 1999, 5, vList);
    //Another PassengerVehicle. Child of list.
    PassengerVehicle *pv = new PassengerVehicle();
    pv->setParent(vList);

//    uses Q_OBJECT macro.
//    QObjectList objList = vList->children();
//    out << "Vehicle list" << endl;

//    foreach(QObject* obj, objList)
//    {
//        out << qobject_cast<vehicle *>(obj)->toString() << endl;
//    }

    QList<vehicle *> objList = vList->findChildren<vehicle *>();
        out << "Vehicle list" << endl;
        foreach(vehicle* obj, objList)
        {
            out << obj->toString() << endl;
        }

    return 0;
}
