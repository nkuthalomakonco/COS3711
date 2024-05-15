#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include "vehicle.h"
#include <QObject>

class TransportVehicle : public vehicle
{
    Q_OBJECT
    public:
        explicit TransportVehicle(QObject *parent = nullptr);
        int get_carrying_capacity()const;

    private:
        int carrying_capacity;

};

#endif // TRANSPORTVEHICLE_H
