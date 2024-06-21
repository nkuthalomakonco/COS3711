#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QStandardItemModel;
class QStandardItem;
class QTableView;
class QDoubleSpinBox;
class QSpinBox;
class QPushButton;
class QLineEdit;
class ProgressBarDelegate;

class window: public QWidget
{
    Q_OBJECT
public:
     window(QWidget *parent = nullptr);
     ~window();

private slots:
    void addItem();
    void updateRow(QStandardItem *item);
    void deleteRow();

private:
    void setupGui();

    QLineEdit *composerEdit;
    QLineEdit *titleEdit;
    QDoubleSpinBox *costEdit;
    QSpinBox *ratingEdit;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QStandardItemModel *model;
    QTableView *view;
    ProgressBarDelegate *progressBarDel;
    void clear();
};

#endif // WINDOW_H
