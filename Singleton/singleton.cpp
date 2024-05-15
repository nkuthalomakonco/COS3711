#include "singleton.h"
#include <QDebug>


Singleton * Singleton::instance = 0;

Singleton::Singleton()
{
    qDebug() << "New Singleton ! "
    << endl;
}
Singleton * Singleton::getInstance()
{
    if (!instance) {
        instance = new Singleton;
    }
    return instance;
}
