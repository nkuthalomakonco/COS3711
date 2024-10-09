#include "widget.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString styleSheetText;
    QFile styleSheetFile(":/files/files/MacOS.qss");
    if (!styleSheetFile.open(QIODevice::ReadOnly)) {
        qWarning() << styleSheetFile.errorString();
    } else {
        styleSheetText = QString::fromUtf8(styleSheetFile.readAll());
        a.setStyleSheet(styleSheetText);
    }
    Widget w;
    w.show();
    return a.exec();
}
