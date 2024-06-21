#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QDialog>

class QLabel;
class QPushButton;
class QTableView;
class QStandardItemModel;
class softwareviews;

class displayWindow : public QDialog
{
    Q_OBJECT
public:
    displayWindow(QList<softwareviews*> );
private:
    void createView();
    QTableView * tableView;
    QStandardItemModel *model;
    QList<softwareviews*> list;
};

#endif // DISPLAYWINDOW_H
