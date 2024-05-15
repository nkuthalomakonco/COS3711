#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addItem();
    void updateDisplay(QStandardItem*);
    void deleteRow();
    void reset();
    void find();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
/*
The QSortFilterProxyModel class provides support for sorting and
filtering data passed between another model and a view.
*/
    QSortFilterProxyModel *proxymodel;
    int current_Year;
};
#endif // MAINWINDOW_H
