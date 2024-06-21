#include "window.h"
#include "filereader.h"

#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QLayout>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>

window::window(QWidget *parent)
    :
    QWidget(parent),
    PushButtonLoad(new QPushButton("Load")),
    PushButtonProcess(new QPushButton("Process")),
    TextEdit(new QTextEdit)
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    TextEdit->setFont(font);

    setWindowTitle(tr("Telephone numbers and email addresses highlighter"));
    setUpGui();

    connect(PushButtonLoad, SIGNAL(clicked(bool)),
            this, SLOT(loadFile()));

    connect(PushButtonProcess, SIGNAL(clicked(bool)),
            this, SLOT(processSlots()));

}

window::~window()
{
    deleteLater();
    delete highlighter;
}

void window::loadFile(const QString &path)
{
    filereader fr;
    TextEdit->setPlainText(fr.read());
    (void)path;
	PushButtonProcess->setEnabled(true);
}

void window::processSlots()
{
    highlighter = new Highlighter(TextEdit->document());

    // connect(TextEdit, &QTextEdit::textChanged,
    //         [&]() {QMessageBox::information(this, tr("Formatting applied"),tr("Check completed.")); });

    QMessageBox::information(this, tr("Formatting applied"),tr("Check completed."));
}
void window::setUpGui()
{
    QHBoxLayout  *HBoxLayout = new QHBoxLayout;
    HBoxLayout->setAlignment(Qt::AlignLeft);
    HBoxLayout->addWidget(PushButtonLoad);
    HBoxLayout->addWidget(PushButtonProcess);
    QVBoxLayout  *VBoxLayout = new QVBoxLayout;
    VBoxLayout->addLayout(HBoxLayout);
    VBoxLayout->addWidget(TextEdit);
    setLayout(VBoxLayout);
	PushButtonProcess->setEnabled(0);
}

