#include "window.h"

#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QTableView>
#include <QPushButton>
#include <QLabel>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QLayout>
#include <QMessageBox>
#include <QDebug>

#include "cd.h"
#include "progressbardelegate.h"

window::window(QWidget *parent)
    :QWidget(parent),
    titleEdit(new QLineEdit()),composerEdit(new QLineEdit()),
    costEdit(new QDoubleSpinBox()),ratingEdit(new QSpinBox),
    view(new QTableView),addButton(new QPushButton("Add")),deleteButton(new QPushButton("Delete")),
    model(new QStandardItemModel(this)), progressBarDel(new ProgressBarDelegate)
{
    setupGui();
    connect(addButton, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteRow()));
    connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(updateRow(QStandardItem*)));
}

window::~window()
{

}

void window::addItem()
{
    QString cd_composer = composerEdit->text();
    QString cd_album = titleEdit->text();
    double cd_costs = costEdit->value();
    int cd_rating = ratingEdit->value();

    if (cd_composer.isEmpty() or cd_album.isEmpty())
    {
        QMessageBox::warning(this, tr("Invalid"),
                             tr("Invalid entry.\n"
                                "Can not add empty entries?"),QMessageBox::Cancel);
        return;}
    clear();

    CD cd(cd_composer,cd_rating,cd_costs,cd_album);//CD(QString composer,int rating,double cost,QString albumName);
    qDebug() << cd.toString();

    // add to model
    QList<QStandardItem*> newRow;
    QStandardItem *cmp = new QStandardItem(cd.getComposer());
    QStandardItem *csts = new QStandardItem();
    //csts->setData(QVariant(cd_costs), Qt::DisplayRole);
    csts->setData(QString::number(cd.getCost(),'f',2), Qt::DisplayRole);
    QStandardItem *albm = new QStandardItem(cd.getAlbumName());
    QStandardItem *rate = new QStandardItem();
    rate->setData(QVariant(cd.getRating()), Qt::DisplayRole);
    newRow <<cmp<<albm<<csts<<rate;
    model->appendRow(newRow);
    updateRow(csts);
}
/*
 Where the replacement value is greater than or equal to R200, the row should be made a different colour.
Note that this colour should also change if the user edits a replacement value
(and it should return to the normal colour if the value drops below R200).
 */
void window::updateRow(QStandardItem *item)
{
    int col = item->column();
    if (col == 2)
    {
        double price = item->data(Qt::DisplayRole).toDouble();
        item->setData(QString::number(price, 'f', 2), Qt::DisplayRole);

        QColor colour = Qt::white;
        int row = item->row();
        if (price >= 200)
            colour = Qt::red;
        for (int col=0; col<4; col++)
            model->item(row, col)->setBackground(colour);
    }
}
/*
The user should be able to delete a row of data.
*/
void window::deleteRow()
{
    QModelIndex index = view->currentIndex();
    if (!index.isValid())
        return;
    if (QMessageBox::Yes == QMessageBox::warning(this, "Delete row", "Are you sure?",
                                                 QMessageBox::Yes | QMessageBox::No))
    {
        int row = index.row();
        model->removeRow(row);
        composerEdit->setFocus();
    }
}
void window::clear()
{
    // reset GUI
    composerEdit->clear();
    titleEdit->clear();
    costEdit->setValue(0);
    ratingEdit->setValue(0);
    composerEdit->setFocus();
}

void window::setupGui()
{
    setWindowTitle("CD Information");

    QLabel *composerLabel = new QLabel("Composer");
    QLabel *albumnameLabel = new QLabel("Album title");
    QLabel *costLabel = new QLabel("Replacement cost");
    QLabel *ratingLabel = new QLabel("Rating");

    composerEdit->setText("Composer");//Test inputs
    titleEdit->setText("Album title");//Test inputs

    costEdit->setRange(0,999);costEdit->setValue(205.00);//Test inputs
    ratingEdit->setRange(0,100);ratingEdit->setValue(50);//Test inputs

    QStringList headerRow = {"Composer","Album title","Replacement cost","Rating"};

    model->setHorizontalHeaderLabels(headerRow);
    view->setModel(model);
    view->setItemDelegateForColumn(3,progressBarDel);
    view->horizontalHeader()->setStretchLastSection(true);
    view->setSortingEnabled(true);

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(composerLabel, 0, 0);
    layout->addWidget(albumnameLabel, 0, 1);
    layout->addWidget(costLabel, 0, 2);
    layout->addWidget(ratingLabel, 0, 3);
    layout->addWidget(composerEdit, 1, 0);
    layout->addWidget(titleEdit, 1, 1);
    layout->addWidget(costEdit, 1, 2);
    layout->addWidget(ratingEdit, 1, 3);
    layout->addWidget(addButton, 1, 4);
    layout->addWidget(view, 2, 0, 1, 5);
    layout->addWidget(deleteButton, 3, 4);
    layout->setRowMinimumHeight(2, 50);
    this->adjustSize();
}
