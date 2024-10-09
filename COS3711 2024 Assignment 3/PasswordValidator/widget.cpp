#include "widget.h"

#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QVBoxLayout>
#include <QButtonGroup>

QRegularExpression Widget::r0(".{5,}");//It must consist of a minimum of five characters
QRegularExpression Widget::r1("\\s");//No spaces are allowed.
QRegularExpression Widget::r2(".{2}[0-9A-Fa-f].{2}");//It must consist of 5 characters, where the third character can be either a digit or an alphabetic character (a-f or A-F).
QRegularExpression Widget::r3("[1-9]\\d{3,5}");//It must consist of a minimum of four and a maximum of six digits and the starting digit cannot be 0

Widget::Widget(QWidget *parent)
    : QWidget(parent),passwordInput(new QLineEdit),validateButton(new QPushButton("Validate")),response(new QLabel())
{
    setUpIU();
}

Widget::~Widget() {}

void Widget::validatePassword()
{

    QString txt = passwordInput->text();

    QRegularExpressionMatch match0 = r0.match(txt);
    QRegularExpressionMatch match1 = r1.match(txt);
    QRegularExpressionMatch match2= r2.match(txt);
    QRegularExpressionMatch match3= r3.match(txt);

    bool flag = false;

    if(rule1->isChecked())
        if(match0.hasMatch() && !match1.hasMatch())
            flag = true;

    if(rule2->isChecked())
        if(match2.hasMatch())
            flag = true;

    if(rule3->isChecked())
        if(match3.hasMatch())
            flag = true;

    if (flag)
        response->setText("Password Valid");
    else
        response->setText("Password Invalid");
    passwordInput->setFocus();
}

void Widget::setUpIU()
{
    setWindowTitle("Password Validator");
    QButtonGroup* group = new QButtonGroup();
    rule1 = new QCheckBox("Rule 1: Minimum 5 characters, no spaces", this);
    rule2 = new QCheckBox("Rule 2: Exactly 5 characters, 3rd can be a digit or a-f/A-F", this);
    rule3 = new QCheckBox("Rule 3: 4 to 6 digits, first digit cannot be 0", this);
    group->addButton(rule1);
    group->addButton(rule2);
    group->addButton(rule3);
    group->setExclusive(true);
    rule1->setChecked(true);

    passwordInput->setPlaceholderText(tr("password..."));

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(rule1);
    layout->addWidget(rule2);
    layout->addWidget(rule3);
    layout->addWidget(passwordInput);
    layout->addWidget(response);
    layout->addWidget(validateButton);

    connect(validateButton, &QPushButton::clicked,this, &Widget::validatePassword);
}
