#include "displaywindow.h"
#include "softwareviews.h"

#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QLayout>
#include <QMetaProperty>

displayWindow::displayWindow(QList<softwareviews*> l)
    : tableView(new QTableView()),list(l)
{
    //Create layout.
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(tableView);
    setWindowTitle("Software reviews list");
    createView();
    resize(350,400);
}
/* Create a table with alll reviews.
 *
 * */
void displayWindow::createView()
{
     model =  new QStandardItemModel;
     tableView->setModel(model);
     tableView->setWindowTitle("Software reviews");
     //resize columns
     tableView->resizeColumnsToContents();
     tableView->horizontalHeader()->setStretchLastSection(true);
     QStringList headerRow = {"Name","Date","Recomend"};
     model->setHorizontalHeaderLabels(headerRow);
     tableView->setAlternatingRowColors(true);

    // add to model
     softwareviews * sr = 0;

     QStringList row;

     QStandardItem *a ;
     QStandardItem *b ;
     QStandardItem *c ;
     for (int i = 0; i < list.size(); ++i) {
         sr = list.at(i);

             const QMetaObject * metaObject = sr->metaObject();

             for(int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i)
             {
                 const char * name = metaObject->property(i).name();
                 QVariant propValue = sr->property(name);
                 QString stri_value = propValue.toString();
                 if (strcmp(name, "recommended") == 0)
                     if (stri_value == "true")
                         stri_value = "Yes";
                     else  stri_value = "No";
                 row << stri_value;
                 //qDebug()<< stri_value;
             }
             a = new QStandardItem(row.at(0));
             b = new QStandardItem(row.at(1));
             c = new QStandardItem(row.at(2));
             QList<QStandardItem*> newRow;
             newRow <<a<<b<<c;
             model->appendRow(newRow);
             row.clear();

     }

}
