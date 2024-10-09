#include "bookinput.h"
#include "bookwriter.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>

BookInput::BookInput()
{

    setWindowTitle("Book Information");
    bw = new BookWriter("books.txt");
    setupGUI();
}

BookInput::~BookInput()
{
    delete bw;
}

void BookInput::setupGUI()
{
    QLabel* titleRequest = new QLabel("Enter title ");
    titleEntry = new QLineEdit();
    QLabel* authorsRequest = new QLabel("Enter authors (separated by comma) ");
    authorsEntry = new QTextEdit();
    QLabel* isbnRequest = new QLabel("Enter ISBN ");
    isbnEntry = new QLineEdit();
    QLabel* dateRequest = new QLabel("Enter publication date (year/month/date) ");
    dateEntry = new QDateEdit(QDate::currentDate());
    submit = new QPushButton("Save");
    QGridLayout* layout = new QGridLayout(this);

    layout->addWidget(titleRequest, 0, 0);
    layout->addWidget(titleEntry, 0, 1);
    layout->addWidget(authorsRequest, 1, 0);
    layout->addWidget(authorsEntry, 1, 1);
    layout->addWidget(isbnRequest, 2, 0);
    layout->addWidget(isbnEntry, 2, 1);
    layout->addWidget(dateRequest, 3, 0);
    layout->addWidget(dateEntry, 3, 1);
    layout->addWidget(submit, 4, 1);
    this->setLayout(layout);

    connect(submit, SIGNAL(clicked()), this, SLOT(readFromGUI()));
}

void BookInput::readFromGUI()
{
    QString tStr = titleEntry->text();
    QString aStr = authorsEntry->toPlainText();
    QString iStr = isbnEntry->text();
    QDate d = dateEntry->date();

    if(!tStr.isEmpty() && !aStr.isEmpty() && !iStr.isEmpty() && !d.isNull())
    {
        QStringList aList = aStr.split(",");
        createAndSaveBook(tStr, aList, iStr, d);
        clear();
    }
    else
    {
        QMessageBox::information(this, "Book Information", "Enter all the necessary information");
    }
}

void BookInput::createAndSaveBook(QString t, QStringList a, QString i, QDate d)
{
    Book b(t, a, i, d);
    bool done = bw->write(b);
    if (done)
        QMessageBox::information(this, "Book Information", "Book information has been saved");
    else
        QMessageBox::critical(this, "Book Information", "Book information has not been saved");
}

void BookInput::clear()
{
    titleEntry->clear();
    authorsEntry->clear();
    isbnEntry->clear();
    dateEntry->setDate(QDate::currentDate());
}
