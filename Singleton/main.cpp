#include "singleton.h"

#include <QApplication>
#include <QTextStream>

QTextStream out(stdout);
/*
class Singleton {
   static Singleton *instance;
   int data;

   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }

   public:
   static Singleton *getInstance() {
      if (!instance)
        instance = new Singleton;
      return instance;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;*/


int main()
{
//    Singleton *s = s->getInstance();
//    out << s->getData() << endl;
//    s->setData(100);
//    out << s->getData() << endl;

    Singleton *singleton1 = Singleton::getInstance();
    Singleton *singleton2 = Singleton::getInstance();

    out << "Singleton1 address: "
    << singleton1 << endl;

    out << "Singleton2 address: "
    << singleton2 << endl;

    return 1;
}
