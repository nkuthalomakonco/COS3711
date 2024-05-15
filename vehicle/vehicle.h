#ifndef VEHICLE_H
#define VEHICLE_H
#include <QObject>


class vehicle: public QObject
{
    Q_OBJECT

    public:
        vehicle();
        virtual ~vehicle();
        vehicle(QString v_model, int v_year,QObject *parent=0);
        void set_model(QString v_model);
        void set_year(int v_year);
        QString get_model()const;
        int get_year()const;
        virtual QString toString()const;

    private:
            QString vehicle_model;
            int vehicle_year;
};

#endif // VEHICLE_H
