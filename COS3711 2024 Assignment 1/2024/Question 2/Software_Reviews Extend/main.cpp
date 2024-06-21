#include "window.h"
//#include "displaywindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    window w;
    w.show();
    //displayWindow newWindow;
    //newWindow.show();
    return a.exec();
}
