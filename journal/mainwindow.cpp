#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDate>
#include <QMessageBox>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Populate comboBox options.
    QStringList lookFor;
    lookFor << "Author" << "Year" << "Title" << "Journal" << "Volume" << "Issue";
    ui->comboBox_Find->addItems(lookFor);
    //Set spinBox_Year max value.
    current_Year = QDate::currentDate().year();
    ui->spinBox_Year->setMaximum(current_Year);
    //model view
    model = new QStandardItemModel(this);
    QStringList headerRow;
    headerRow.append("Author");//headerRow << "Author" << "Year" << "Title" << "Journal" << "Volume" << "Issue" <<"Pages";
    headerRow.append("Year");
    headerRow.append("Title");
    headerRow.append("Journal");
    headerRow.append("Volume");
    headerRow.append("Issue");
    headerRow.append("Pages");
    model->setHorizontalHeaderLabels(headerRow);

    //QSortFilterProxyModel can be used for sorting items, filtering out items, or both.
    proxymodel = new QSortFilterProxyModel(this);
    proxymodel->setSourceModel(model);
    //QTableView view set up in GUI
    ui->tableView->setModel(proxymodel);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSortingEnabled(true);

    // set up signals and slots
    connect(ui->pushButton_Add, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(updateDisplay(QStandardItem*)));
    connect(ui->pushButton_Remove, SIGNAL(clicked()), this, SLOT(deleteRow()));
    connect(ui->pushButton_reset, SIGNAL(clicked()), this, SLOT(reset()));
    connect(ui->pushButton_Find, SIGNAL(clicked()), this, SLOT(find()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItem()
{
    // get values
    QString author = ui->lineEdit_Author->text();
    QString title = ui->lineEdit_Title->text();
    int year = ui->spinBox_Year->value();
    int volume = ui->spinBox_Volume->value();

    // reset GUI
  /*  ui->lineEdit_Author->clear();
    ui->spinBox_Year->setValue(1900);
    ui->lineEdit_Title->clear();
    ui->spinBox_Volume->setValue(0);*/
    ui->lineEdit_Author->setFocus();

    // add to model
    QList<QStandardItem*> newRow;
    QStandardItem *itemAuthor = new QStandardItem(author);
    QStandardItem *itemYear = new QStandardItem();
    itemYear->setData(QVariant(year), Qt::DisplayRole);//
    QStandardItem *itemTitle = new QStandardItem(title);
    QStandardItem *itemVolume = new QStandardItem();
    itemVolume->setData(QVariant(volume), Qt::DisplayRole);//

    //
    newRow << itemAuthor << itemYear << itemTitle << itemVolume;
    //
    model->appendRow(newRow);
    //
    updateDisplay(itemYear);

}

void MainWindow::updateDisplay(QStandardItem *item)
{
    int row = item->row();  // get row number
    int itemsYear = model->item(row, 1)->data(Qt::DisplayRole).toInt();

    int yearDifference = current_Year - itemsYear;

    QColor colour = Qt::white;
    if (yearDifference < 5)
        colour = Qt::green;
    else if (yearDifference > 5)
        colour = Qt::red;
    for (int col=0; col<7; col++)
        //model->item(row, col)->setBackground(colour);//????
    // resize columns
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::deleteRow()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid())
        return;
    if (QMessageBox::Yes == QMessageBox::warning(this, "Delete row", "Are you sure?", QMessageBox::Yes | QMessageBox::No))
        {
            int row = index.row();
            proxymodel->removeRow(row);
    }
}

void MainWindow::reset()
{
    proxymodel->setFilterWildcard("");//???
    //void QSortFilterProxyModel::setFilterWildcard(const QString &pattern)
    //ets the wildcard expression used to filter the contents of the source model to the given pattern.
}

void MainWindow::find()
{
    proxymodel->setFilterKeyColumn(ui->comboBox_Find->currentIndex());
    proxymodel->setFilterWildcard(ui->lineEdit_Find->text());
}

