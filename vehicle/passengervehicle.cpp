#include "passengervehicle.h"

PassengerVehicle::PassengerVehicle()
    :vehicle("v_model",1990),number_of_passengers(0)
{

}

PassengerVehicle::PassengerVehicle(QString v_model, int v_year, int passengers, QObject *parent)
    :vehicle(v_model,v_year,parent),number_of_passengers(passengers)
{

}

QString PassengerVehicle::toString() const
{
    return QString(vehicle::toString() + ", " + QString::number(number_of_passengers));
}

int PassengerVehicle::get_number_of_passengers() const
{
    return number_of_passengers;
}

void PassengerVehicle::set_number_of_passengers(int number_of_passengers_)
{
    if(number_of_passengers!=number_of_passengers_)
        number_of_passengers = number_of_passengers_;
}
