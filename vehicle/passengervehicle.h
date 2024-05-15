#ifndef PASSENGERVEHICLE_H
#define PASSENGERVEHICLE_H

#include "vehicle.h"
#include <QObject>

class PassengerVehicle : public vehicle
{
    Q_OBJECT

    public:
        PassengerVehicle();
        PassengerVehicle(QString v_model,int v_year,int passengers,QObject *parent = nullptr);
        QString toString()const;
        int get_number_of_passengers()const;
        void set_number_of_passengers(int number_of_passengers_);

    private:
        int number_of_passengers;

};

#endif // PASSENGERVEHICLE_H
