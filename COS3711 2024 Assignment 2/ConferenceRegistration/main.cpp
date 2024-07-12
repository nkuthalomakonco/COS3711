#include <QApplication>
#include <QDebug>
#include <QFile>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString styleSheetText;
    QFile styleSheetFile(":/files/files/MacOS.qss");
    if (!styleSheetFile.open(QIODevice::ReadOnly)) {
        qWarning() << styleSheetFile.errorString();
    } else {
        styleSheetText = QString::fromUtf8(styleSheetFile.readAll());
        app.setStyleSheet(styleSheetText);
    }
    MainWindow w;
    w.show();
    return app.exec();
}
