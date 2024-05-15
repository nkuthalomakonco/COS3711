#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <QObject>

class VehicleList : public QObject
{
    Q_OBJECT
public:
    explicit VehicleList(QObject *parent = nullptr);

};

#endif // VEHICLELIST_H
