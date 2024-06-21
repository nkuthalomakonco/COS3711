#ifndef PHONENUMBERSANDEMAILSHIGHLIGHTER_H
#define PHONENUMBERSANDEMAILSHIGHLIGHTER_H

#include <QRegularExpression>
#include <QTextCursor>
#include <QTextEdit>

class PhoneNumbersAndEmailsHighlighter
{
public:
    PhoneNumbersAndEmailsHighlighter();
    void highlight(QTextEdit *textEdit);
};



#endif // PHONENUMBERSANDEMAILSHIGHLIGHTER_H
