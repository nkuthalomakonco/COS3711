#include "filereader.h"

#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

filereader::filereader()
{

}

QString filereader::read()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open File",
                                                        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),
                                                        "Text file (*.txt)");

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
		//file.errorString();
        QMessageBox::critical(0,"File error", "Could not open file " + fileName, QMessageBox::Ok);
        return QString();
    }
    QTextStream in(&file);
    QString contents = in.readAll();
    file.close();
    return contents;
}
