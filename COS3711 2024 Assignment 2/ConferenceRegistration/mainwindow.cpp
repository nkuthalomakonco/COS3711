#include "mainwindow.h"

#include <QLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QCloseEvent>
#include <QStatusBar>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QTableWidget>
#include <QTableView>
#include <QTableWidgetItem>
#include <QApplication>
#include <QStandardItemModel>
#include <QMetaProperty>
#include <QSortFilterProxyModel>
#include <QFileDialog>
#include <QMenuBar>
#include <QToolBar>
#include <QRandomGenerator>

#include "tablemodel.h"
#include "registrationlistwriter.h"
#include "registrationlistreader.h"
#include "registrationfactory.h"

struct info
{
public:
    QString name;
    QString aff;
    QString email;
};

MainWindow::MainWindow(): m_name(new QLineEdit()),
    m_affiliation(new QLineEdit()),
    m_email(new QLineEdit()),m_registration_type(new QComboBox),m_viewer(new QComboBox),m_table(new QTableWidget), m_tableView(new QTableView),
    m_add_registration(new QPushButton("Add")),m_qualification(new QLineEdit), m_catergory(new QLineEdit),
    model(new TableModel),proxymodel(new QSortFilterProxyModel),m_save(new QPushButton("save")),m_open(new QPushButton("open")),
    m_search(new QPushButton("search")),m_searchName(new QLineEdit),m_totalfee(new QPushButton("total"))
{
    setupContainerWidget();

    createToolBar();

    connect(m_add_registration, SIGNAL(clicked()), this, SLOT(addRegistration()));
    connect(m_search, SIGNAL(clicked()), this, SLOT(search()));
    connect(m_totalfee, SIGNAL(clicked()), this, SLOT(totalfee()));
    connect(m_open, SIGNAL(clicked()), this, SLOT(open()));

    connect(m_registration_type, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChanged(int)));
    connect(m_viewer, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChangedviewer(int)));
    connect(m_viewer, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChangedviewer(int)));
    // Using lambda to connect signal
    connect(m_viewer, &QComboBox::currentIndexChanged, [this](int value) {
        if (value == 0)
        {
            QStringList n;
                            n << QStringLiteral("Thabo")
                              << QStringLiteral("Nomalanga")
                              << QStringLiteral("Sipho")
                              << QStringLiteral("Lerato")
                              << QStringLiteral("Bongani")
                              << QStringLiteral("Zanele")
                              << QStringLiteral("Kgosi")
                              << QStringLiteral("Naledi")
                              << QStringLiteral("Jabulani")
                              << QStringLiteral("Amahle")
                              << QStringLiteral("Lethabo")
                              << QStringLiteral("Thandiwe")
                              << QStringLiteral("Mandla")
                              << QStringLiteral("Refilwe")
                              << QStringLiteral("Sizwe")
                              << QStringLiteral("Ayanda")
                              << QStringLiteral("Nokuthula")
                              << QStringLiteral("Sibusiso")
                              << QStringLiteral("Thandi")
                              << QStringLiteral("Ntombi");
            QString user = n.at(QRandomGenerator::global()->bounded(n.size()));
            // List of domains to randomly choose from
            QStringList domains = {"gmail.com", "yahoo.com", "hotmail.com", "outlook.com", "aol.com"};

            // Generate a random username and domain
            QString username = user + QString::number(QRandomGenerator::global()->bounded(1000)); // Random number for username
            QString domain = domains.at(QRandomGenerator::global()->bounded(domains.size()));

            // Construct and return the email address
            QString E = username + "@" + domain;

            //for testing
            m_name->setText(user);
            m_affiliation->setText(tr("Affiliation"));
            m_email->setText(E);
            m_qualification->setText(tr("Qualification"));
            m_catergory->setText(tr("Catergory"));
        }
    });
    connect(m_searchName, SIGNAL(textChanged(QString)), this, SLOT(reset(QString)));

    connect(m_save, SIGNAL(clicked()), this, SLOT(save()));

    proxymodel->setSourceModel(model);
    m_tableView->setModel(proxymodel);
    proxymodel->setFilterCaseSensitivity(Qt::CaseInsensitive);

}

MainWindow::~MainWindow()
{

}

void MainWindow::addRegistration()
{
    statusBar()->showMessage(Q_FUNC_INFO);

    if(!validInput()) {
        QMessageBox::information(this, tr("Invalid input"),
                                 tr("Invalid input, enter the correct registration information."
                                    ""));
        return;}

    //get values from gui.

    QString type = m_registration_type->currentText();
    //Implement a factory class (RegistrationFactory)
    //Make the RegistrationFactory an implementation of the Singleton pattern.
    RegistrationFactory rf = *RegistrationFactory::getInstance();

    Registration *r = rf.createRegistration(type,m_name->text(),m_email->text(),m_affiliation->text(),m_catergory->text(),m_qualification->text());

    if(model->contains(r)){
        QMessageBox::information(this, tr("Duplicate registration"),
                                 tr("<b>Registration already in the list.</b>  "
                                    " No two registrations are allowed to have attendees with the same e-mail addresses, unless the names are different."));
        return;}
    if(r){model->addRegistration(r);
    QMessageBox::information(this, tr("Registration"),
                             tr("<b>Registration added to the list.</b>  "
                                    ""));}
    clearInput();
    m_tableView->resizeColumnsToContents();
    statusBar()->showMessage(tr(Q_FUNC_INFO), 2000);
}

void MainWindow::currentIndexChanged(int v)
{

    m_qualification->setEnabled(false);
   m_catergory->setEnabled(false);
    if (v == 1) {
        m_qualification->setEnabled(true);
    }else if(v == 2 ){
        m_catergory->setEnabled(true);
    }else{
        m_qualification->setEnabled(false);
        m_catergory->setEnabled(false);
    }
}
//currentIndexChangedviewer
void MainWindow::currentIndexChangedviewer(int v)
{
    proxymodel->setFilterKeyColumn(7);
    if(v == 1)proxymodel->setFilterFixedString("Registration");
    else if(v == 2)proxymodel->setFilterFixedString("GuestsRegistration");
    else if(v == 3)proxymodel->setFilterFixedString("StudentRegistration");
    else proxymodel->setFilterFixedString("");
}

void MainWindow::setupContainerWidget()
{
    statusBar()->showMessage("setupContainerWidget");
    setWindowTitle("Conference registrations");
    resize(650,600);

    QWidget *containerWidget(new QWidget);

    QGroupBox *groupBox = new QGroupBox(tr("Person info"));
    QFormLayout *finputslayout = new QFormLayout;

    finputslayout->addRow(new QLabel(tr("Name")), m_name); m_name->setMaximumWidth(200);
    finputslayout->addRow(new QLabel(tr("Affiliation")), m_affiliation);m_affiliation->setMaximumWidth(200);
    finputslayout->addRow(new QLabel(tr("Email")), m_email);m_email->setMaximumWidth(200);
    finputslayout->addRow(new QLabel(tr("Qualification")), m_qualification);m_qualification->setMaximumWidth(200);
    finputslayout->addRow(new QLabel(tr("Catergory")), m_catergory);m_catergory->setMaximumWidth(200);
    finputslayout->addRow(new QLabel(tr("Type")), m_registration_type);m_registration_type->setMaximumWidth(200);

    groupBox->setLayout(finputslayout);

    QHBoxLayout *hbox = new QHBoxLayout;

    hbox->addWidget(groupBox);
    hbox->addWidget(m_add_registration,0,Qt::AlignBottom);m_add_registration->setToolTip("add registration.");

    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addLayout(hbox);
    vbox->addWidget(m_tableView);
    QFormLayout *flayout = new QFormLayout;
    flayout->addRow(new QLabel(tr("view")), m_viewer);m_viewer->setMaximumWidth(150);
    flayout->addRow(new QLabel(tr("search")), m_searchName); m_searchName->setPlaceholderText("search...");m_searchName->setMaximumWidth(150);
    vbox->addLayout(flayout);
    vbox->addWidget(m_search);m_search->setMaximumWidth(170);
    vbox->addWidget(m_totalfee);m_totalfee->setMaximumWidth(170);


    QHBoxLayout *hboxfile = new QHBoxLayout;

    hboxfile->addWidget(m_open,0);m_open->setMaximumWidth(100); m_open->setToolTip("open/load list from xml file.");
    hboxfile->addWidget(m_save,0);m_save->setMaximumWidth(100); m_save->setToolTip("save list to xml file.");

    vbox->addLayout(hboxfile);

    m_tableView->setAlternatingRowColors(true);


    containerWidget->setLayout(vbox);

    setCentralWidget(containerWidget);

    m_registration_type->addItem("standard");
    m_registration_type->addItem("student");
    m_registration_type->addItem("guest");
    m_qualification->setEnabled(false);
    m_catergory->setEnabled(false);

    m_viewer->addItems(QStringList()<< "all"<<"standard"<<"guests"<<"students");

    setWindowIcon(QIcon(":/files/files/registration.png"));

}

void MainWindow::createActions()
{

}

void MainWindow::createToolBar()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));

    QAction *openAct = new QAction(QIcon(":/files/files/folder.png"),tr("&Open"), this);

    openAct->setStatusTip(tr("Open list from xml file."));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
    fileMenu->addAction(openAct);
    fileToolBar->addAction(openAct);

    QAction *saveAct = new QAction(QIcon(":/files/files/diskette.png"),tr("&Save"), this);
    saveAct->setStatusTip(tr("Save list to xml file."));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);
    fileMenu->addAction(saveAct);
    fileToolBar->addAction(saveAct);

    QAction *addAct = new QAction(QIcon(":/files/files/add.png"),tr("&Add"), this);
    QAction *calculateAct = new QAction(QIcon(":/files/files/count.png"),tr("&Calculate"), this);
    QAction *searchAct = new QAction(QIcon(":/files/files/search.png"),tr("&Search"), this);
    fileToolBar->addAction(addAct);
    fileToolBar->addAction(calculateAct);
    fileToolBar->addAction(searchAct);
    addAct->setStatusTip(tr("Add reg to list."));
    calculateAct->setStatusTip(tr("Calculate total fees."));
    searchAct->setStatusTip(tr("Search name."));

    connect(addAct, &QAction::triggered, this, &MainWindow::addRegistration);
    connect(calculateAct, &QAction::triggered, this, &MainWindow::totalfee);
    connect(searchAct, &QAction::triggered, this, &MainWindow::search);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);


}

bool MainWindow::validInput()
{
    if(m_name->text().isEmpty())return false;
    if(m_email->text().isEmpty())return false;
    if(m_affiliation->text().isEmpty())return false;
    if(m_catergory->text().isEmpty())return false;
    if(m_qualification->text().isEmpty())return false;
    return true;
}

void MainWindow::clearInput()
{
    m_name->clear();
    m_email->clear();
    m_affiliation->clear();
    m_catergory->clear();
    m_qualification->clear();
    m_registration_type->setCurrentIndex(0);
}
void MainWindow::reset(QString txt)
{
   if(m_searchName->text().isEmpty()) proxymodel->setFilterWildcard("");
}
void MainWindow::search()
{

    proxymodel->setFilterKeyColumn(0);
    proxymodel->setFilterFixedString(m_searchName->text());

}
void MainWindow::totalfee()
{

    QString txt = m_viewer->currentText();
    double fee = model->getTotalFee(txt);
    int t = model->getList().size(); (void)t;
    QMessageBox::information(this, tr("Fee"),
                             QString("Total fee for %1 : %2").arg(txt,QString::number(fee)));

}
void MainWindow::save(){
    if(model->getList().size()==0){
        QMessageBox::information(this, tr("Registration list is empty."),
                                 tr("<b>Registration list is empty.</b> "
                                    " Can not save an empty list."));
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "Text files (*.xml)");
    RegistrationListWriter w(model);
    bool done = w.write(fileName);
    statusBar()->showMessage(QString::number(done), 1000);
    if(done) statusBar()->showMessage(tr("File saved"), 2000);
    if(done) QMessageBox::information(this, tr("Registrations save"),
                             tr("<b>Registration saved to xml file</b>  "
                                "done."));
}

void MainWindow::open()
{
     QString fileName = QFileDialog::getOpenFileName(this, "Open File",QDir::homePath(), "Text files (*.xml)");
     RegistrationListReader lr;
     QList<Registration*> list = lr.read(fileName);
     if(!list.empty()) {model->setList(list);
        QMessageBox::information(this, tr("Registrations file open"),
                                 tr("<b>Registration read from the xml file</b>  "
                                    "done."));
     }else {
         QMessageBox::information(this, tr("Registrations from file"),
                                  tr("<b>No Registration read from the xml file</b>  "
                                     ".")); return;
     }
     m_tableView->resizeColumnsToContents();
     statusBar()->showMessage(QString::number(list.size()), 2000);
}

void MainWindow::about()
{
     QMessageBox::about(this, tr("About Conference registrations"),
                        tr("The <b>Conference registrations</b> captures registrations, "
                           "standard registration, student registration and invited guests registration."));
}
