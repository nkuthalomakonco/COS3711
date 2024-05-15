#include "vehicle.h"

vehicle::vehicle()
    :vehicle_model("Vehicle"),vehicle_year(1999)
{

}

vehicle::~vehicle()
{

}

vehicle::vehicle(QString v_model, int v_year, QObject *parent)
    :QObject(parent),vehicle_model(v_model)
{
    //if(vehicle_model!=v_model) vehicle_model = v_model;use on set.

    if(vehicle_year!=v_year and v_year>=1800 and v_year<=2022)
        vehicle_year = v_year;
    else
        vehicle_year = 9999;
}

QString vehicle::toString() const
{
    return QString(vehicle_model + ", " + QString::number(vehicle_year));
}
