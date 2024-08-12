#include "filewriter.h"

#include <QFile>
#include <QTextStream>
#include <QStandardPaths>

FileWriter::FileWriter(QString fName)
    : fileName(fName)
{
}

bool FileWriter::write(QString str) const
{
    //QString fn = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) +"/"+ fileName;

    QFile outFile(fileName);

    if (!outFile.open(QIODevice::WriteOnly)) {
        return false;
    }

    QTextStream out(&outFile);
    out << str;
    out.flush();  // Flush buffer to ensure all data written to file

    outFile.close();

    return true;
}
