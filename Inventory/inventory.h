#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QMap>

class Inventory : public QObject
{
        Q_OBJECT
    public:
        explicit Inventory(QObject *parrent = nullptr);
        void add(QString, int);
        void remove(QString, int);
        void list();

    public slots:
        void save();//
        void load();

    private:
        QMap<QString,int> m_items;
};

#endif // INVENTORY_H
