#include "window.h"
#include "softwareviews.h"
#include "displaywindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QDateEdit>
#include <QCheckBox>
#include <QPushButton>

#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QMetaProperty>

window::window()
{
    setupGUI();
}

window::~window()
{
    qDeleteAll(softWareReviews);
    softWareReviews.clear();
}

void window::add_softwareview()
{

    QString w_name = name->text();
    QDate w_date = dateEdit->date();
    bool recommend = CheckBox->isChecked();

    const int size = softWareReviews.size();

    if(w_name.isEmpty())
    {QMessageBox::information(this, tr("Invalid"),
                                 tr("Software name not inserted. Fill in all data."));
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

    if(softWareReviews.size()==0)return;
    QTextStream out(stdout, QIODevice::WriteOnly);
    for ( const auto data : softWareReviews )
    {
        out << data->toString() << Qt::endl;
    }
}
/* Extend Question 1 so that it uses reflective programming techniques
  to access the data members of the object that holds the review data.
*/
void window::reflectiveDisplay()
{

    if(softWareReviews.size()==0)return;

    QString line;

    QTextStream out(stdout);

    foreach(const auto sr, softWareReviews)
    {
        const QMetaObject * metaObject = sr->metaObject();
        line.clear();
        for(int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i)
        {
            const char * name = metaObject->property(i).name(); //qDebug() << "property: " << name;
            QVariant propValue = sr->property(name);
            QString stri_value = propValue.toString();
            if (strcmp(name, "recommended") == 0 && propValue.canConvert<bool>())//or propValue.canConvert<bool>();
                if (stri_value == "true")
                    stri_value = "Yes";
                else  stri_value = "No";
            line.append(QString("%1 : %2 ").arg(name,stri_value));
        }

        out << line << Qt::endl;
    }

    reflectiveDisplayWindow();
}
/*
Also add a button to display the review detail to the application window (so that the program now can print to the console or GUI window).
*/
void window::reflectiveDisplayWindow()
{
    displayWindow newWindow(softWareReviews);
    newWindow.exec();
}

void window::setupGUI()
{
    setWindowTitle("Software Reviews");

    name = new QLineEdit;

    dateEdit = new QDateEdit(QDate::currentDate());

    CheckBox =  new QCheckBox("Recommended");

    add = new QPushButton("Add");
    display = new QPushButton("Display");
    reflectivePrint = new QPushButton("Rftv display");
    add->setToolTip("Add review.");
    display->setToolTip("Display all reviews.");
    reflectivePrint->setToolTip("Reflective techniques to access the data members.");

    gridLayout = new QGridLayout();

    gridLayout->addWidget(new QLabel("Fill in data and add."),0,0);
    gridLayout->addWidget(new QLabel("Name"),1,0);
    gridLayout->addWidget(name,1,1);
    gridLayout->addWidget(new QLabel("Date"),2,0);
    gridLayout->addWidget(dateEdit,2,1);
    gridLayout->addWidget(CheckBox,3,1);
    gridLayout->addWidget(add,4,0);
    gridLayout->addWidget(display,4,1);
    gridLayout->addWidget(reflectivePrint,5,1);

    this->setLayout(gridLayout);

    connect(add, SIGNAL(clicked()), this, SLOT(add_softwareview()));
    connect(display, SIGNAL(clicked()), this, SLOT(print()));
    connect(reflectivePrint, SIGNAL(clicked()), this, SLOT(reflectiveDisplay()));
}

void window::reset()
{
    name->clear();
    dateEdit->setDate(QDate::currentDate());
    CheckBox->setChecked(false);
}
