#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;
class QRadioButton;
class QPushButton;
class QLineEdit;
class QComboBox;
class QSortFilterProxyModel;
class QStandardItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

private slots:
    void addRegistration();
    void currentIndexChanged(int);
    void search();
    void currentIndexChangedviewer(int v);
    void totalfee();
    void reset(QString txt);
    void save();
    void open();
    void about();
private:
    void setupContainerWidget();
    void upDateTable();
    void createActions();
    void createToolBar();

private:
    QLineEdit *m_name;
    QLineEdit *m_affiliation;
    QLineEdit *m_email;
    QComboBox *m_registration_type;
    QComboBox *m_viewer;
    QPushButton *m_search;
    QPushButton *m_totalfee;
    QLineEdit *m_searchName;
    QPushButton *m_add_registration;
    QPushButton *m_save;
    QPushButton *m_open;
    QTableWidget *m_table;
    QTableView *m_tableView;
    QLineEdit *m_qualification, *m_catergory;
    TableModel *model;
    QSortFilterProxyModel *proxymodel;

};
#endif // MAINWINDOW_H
