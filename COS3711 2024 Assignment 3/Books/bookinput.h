#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QWidget>

class QLineEdit;
class QTextEdit;
class QDateEdit;
class QPushButton;
class BookWriter;

class BookInput: public QWidget
{
    Q_OBJECT
public:
    BookInput();
    ~BookInput();
public slots:
    void readFromGUI();
private:
    void clear();
    void setupGUI();
    void createAndSaveBook(QString t, QStringList a, QString i, QDate d);
    QLineEdit *titleEntry;
    QTextEdit *authorsEntry;
    QLineEdit *isbnEntry;
    QDateEdit *dateEntry;
    QPushButton *submit;
    BookWriter *bw;

};
#endif // BOOKINPUT_H



