#include "bookinput.h"
#include <QLabel>

BookInput::BookInput()
{
    setWindowTitle("BookInput");
    setUpGui();
}

void BookInput::setUpGui()
{
    title = new QLineEdit; QLabel *title_l = new QLabel("Title");
    authors = new QTextEdit;QLabel *authors_l = new QLabel("Authors");
    date = new QDateEdit(QDate::currentDate());QLabel *date_l = new QLabel("Date");
    isbn = new QLineEdit; QLabel *isbn_l = new QLabel("isbn");
    add_button = new QPushButton("Add");
    save_button = new QPushButton("Save");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(title_l,0,0);
    layout->addWidget(title,0,1);
    layout->addWidget(authors_l,1,0);
    layout->addWidget(authors,1,1);
    layout->addWidget(isbn_l,2,0);
    layout->addWidget(isbn,2,1);
    layout->addWidget(date_l,3,0);
    layout->addWidget(date,3,1);
    layout->addWidget(add_button,4,0,Qt::Alignment(Qt::AlignLeft));
    layout->addWidget(save_button,4,1,Qt::Alignment(Qt::AlignRight));

    this->setLayout(layout);
}

BookInput::~BookInput()
{

}

void BookInput::getFromGui()
{
    QString b_title = title->text();
    QString b_authors = authors->toPlainText();
    QString b_date = date->date().toString();
    QString b_isbn = isbn->text();
}

void BookInput::save()
{

}


