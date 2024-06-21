#include "window.h"
#include "filereader.h"
#include "phonenumbersandemailshighlighter.h"

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

    // QTextCharFormat highlightFormat;

    // highlightFormat.setForeground(Qt::darkBlue);
    // highlightFormat.setFontWeight(QFont::Bold);

    // QString text = TextEdit->toPlainText();

    // QRegularExpression phoneRegex("(\\+?1[- ]?)?\\(?(\\d{3,3})\\)?[\\s-]?(\\d{3,3})[\\s-]?(\\d{4,4})");
    // QRegularExpressionMatchIterator phoneMatches = phoneRegex.globalMatch(text);

    // QTextCursor cursor(TextEdit->document());
    // while (phoneMatches.hasNext()) {
    //     QRegularExpressionMatch match = phoneMatches.next();
    //     cursor.setPosition(match.capturedStart());
    //     cursor.setPosition(match.capturedEnd(), QTextCursor::KeepAnchor);
    //     cursor.setCharFormat(highlightFormat);
    // }

    // QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    // QRegularExpressionMatchIterator emailMatches = emailRegex.globalMatch(text);

    // highlightFormat.setForeground(Qt::darkRed);

    // while (emailMatches.hasNext()) {
    //     QRegularExpressionMatch match = emailMatches.next();
    //     cursor.setPosition(match.capturedStart());
    //     cursor.setPosition(match.capturedEnd(), QTextCursor::KeepAnchor);
    //     cursor.setCharFormat(highlightFormat);
    // }

    PhoneNumbersAndEmailsHighlighter h;
    h.highlight(TextEdit);

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

    PushButtonProcess->setEnabled(false);
}

