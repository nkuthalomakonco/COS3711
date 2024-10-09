
#include "bookinput.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BookInput w;
    w.show();
    return a.exec();
}
