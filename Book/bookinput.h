#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QLineEdit>
#include <QTextEdit>
#include <QLayout>
#include <QPushButton>

class BookInput: public QWidget
{
    Q_OBJECT
public:
     BookInput();
     ~BookInput();

public slots:
     void getFromGui();//add clicked.
     void save();//

private:
     void setUpGui();
     QLineEdit *title;
     QDateEdit *date;
     QLineEdit *isbn;
     QTextEdit *authors;
     QPushButton *add_button;
     QPushButton *save_button;
};

#endif // BOOKINPUT_H
