#include "phonenumbersandemailshighlighter.h"

PhoneNumbersAndEmailsHighlighter::PhoneNumbersAndEmailsHighlighter() {}

void PhoneNumbersAndEmailsHighlighter::highlight(QTextEdit *textEdit)
{
    QTextCharFormat highlightFormat;

    highlightFormat.setForeground(Qt::darkBlue);
    highlightFormat.setFontWeight(QFont::Bold);

    QString text = textEdit->toPlainText();

    //QRegularExpression phoneRegex("\\b\\d{3}[-.\\s]?\\d{3}[-.\\s]?\\d{4}\\b");
    QRegularExpression phoneRegex("(\\+?1[- ]?)?\\(?(\\d{3,3})\\)?[\\s-]?(\\d{3,3})[\\s-]?(\\d{4,4})");
    QRegularExpressionMatchIterator phoneMatches = phoneRegex.globalMatch(text);

    QTextCursor cursor(textEdit->document());
    while (phoneMatches.hasNext()) {
        QRegularExpressionMatch match = phoneMatches.next();
        cursor.setPosition(match.capturedStart());
        cursor.setPosition(match.capturedEnd(), QTextCursor::KeepAnchor);
        cursor.setCharFormat(highlightFormat);
    }

    QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    QRegularExpressionMatchIterator emailMatches = emailRegex.globalMatch(text);

    highlightFormat.setForeground(Qt::darkRed);

    while (emailMatches.hasNext()) {
        QRegularExpressionMatch match = emailMatches.next();
        cursor.setPosition(match.capturedStart());
        cursor.setPosition(match.capturedEnd(), QTextCursor::KeepAnchor);
        cursor.setCharFormat(highlightFormat);
    }

}
