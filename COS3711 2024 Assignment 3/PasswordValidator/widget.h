#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLineEdit;
class QCheckBox;
class QLineEdit;
class QPushButton;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void validatePassword();

private:
    void setUpIU();
    QLineEdit *passwordInput;
    QCheckBox *rule1;
    QCheckBox *rule2;
    QCheckBox *rule3;
    QPushButton *validateButton;
    QLabel *response;

    static QRegularExpression r0;
    static QRegularExpression r1;
    static QRegularExpression r2;
    static QRegularExpression r3;

};
#endif // WIDGET_H
