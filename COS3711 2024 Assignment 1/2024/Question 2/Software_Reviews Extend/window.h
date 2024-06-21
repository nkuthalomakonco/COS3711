#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QLabel;
class QLineEdit;
class QDateEdit;
class QLineEdit;
class QPushButton;
class QCheckBox;
class QGridLayout;

class softwareviews;

class window : public QWidget
{
    Q_OBJECT
public:
    window();
    ~window();

public slots:
    void add_softwareview();
    void print();
    void reflectiveDisplay();
    void reflectiveDisplayWindow();

signals:

private:
    void setupGUI();
    void reset();
    QLineEdit *name;
    QDateEdit *dateEdit;
    QCheckBox *CheckBox;
    QPushButton *add;
    QPushButton *display,*reflectivePrint;
    QGridLayout *gridLayout;
    QList<softwareviews*> softWareReviews;
};

#endif // WINDOW_H
