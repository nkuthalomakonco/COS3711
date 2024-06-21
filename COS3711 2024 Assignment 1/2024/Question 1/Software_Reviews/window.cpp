#include "window.h"
#include "softwareviews.h"

#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QDateEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>

#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QDir>

QTextStream out(stdout);

window::window()
{
    setupGUI();
}

window::~window()
{
    qDeleteAll(softWareReviews);
    softWareReviews.clear();
}

void window::add_softwareviews()
{

    QString w_name = name->text();
    QDate w_date = dateEdit->date();
    bool recommend = CheckBox->isChecked();

    const int size = softWareReviews.size();
    //for testing
    // if(w_name.isEmpty())
    //     w_name = "software unkown";
    if(w_name.isEmpty())
    {QMessageBox::information(this, tr("Invalid"),
                                 tr("Software name invalid. Fill in correct info."));
        return;
    }

    auto sr = new softwareviews(w_name,w_date,recommend);

    softWareReviews.append(sr);

    if(size != softWareReviews.size())
        QMessageBox::information(this, tr("Added"),
                                 tr("Software view added.\n%1").arg(sr->toString()));

    reset();
}
/*
Data should be stored in an appropriate container (allowing for several reviews to be recorded),
and be printed to a console window when required.
*/
void window::print()
{

    qDebug() << QString("Number of softwareviews : %1").arg(softWareReviews.size());
    if(softWareReviews.size()==0)return;
    QTextStream out(stdout, QIODevice::WriteOnly);
    for ( const auto data : softWareReviews )
    {
        out << data->toString() << Qt::endl;
    }
}
/*
You should create a graphical user interface that allows a user to enter the data.
*/
void window::setupGUI()
{
    setWindowTitle("Softwa Reviews");

    name = new QLineEdit;

    dateEdit = new QDateEdit(QDate::currentDate());

    CheckBox =  new QCheckBox("Recommended");

    add = new QPushButton("Add");
    display = new QPushButton("Display");

    gridLayout = new QGridLayout();

    gridLayout->addWidget(new QLabel("Fill in data and add."),0,0);
    gridLayout->addWidget(new QLabel("Name"),1,0);
    gridLayout->addWidget(name,1,1);
    gridLayout->addWidget(new QLabel("Date"),2,0);
    gridLayout->addWidget(dateEdit,2,1);
    gridLayout->addWidget(CheckBox,3,1);
    gridLayout->addWidget(add,4,0);
    gridLayout->addWidget(display,4,1);

    this->setLayout(gridLayout);

    connect(add, SIGNAL(clicked()), this, SLOT(add_softwareviews()));
    connect(display, SIGNAL(clicked()), this, SLOT(print()));
}

void window::reset()
{
    name->clear();
    dateEdit->setDate(QDate::currentDate());
    CheckBox->setChecked(false);
}
