
#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

        QRegularExpression telephone("(\\+?1[- ]?)?\\(?(\\d{3,3})\\)?[\\s-]?(\\d{3,3})[\\s-]?(\\d{4,4})");
        QRegularExpression email("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
		//telephone = QRegularExpression("(\\+?1[- ]?)?\\(?(\\d{3,3})\\)?[\\s-]?(\\d{3,3})[\\s-]?(\\d{4,4})");
		//email = QRegularExpression("[\\w-]+@([\\w-]+\\.)+[\\w-]{2,4}");
        QFont font;
        //font.setFamily("Courier");
        //font.setFixedPitch(true);
        //font.setPointSize(10);
        font.setBold(true);

        fm.setBackground(Qt::yellow);
        fm.setFont(font);
        rule.pattern = telephone;
        rule.format = fm;
        highlightingRules.append(rule);

        fm.setBackground(Qt::red);
        rule.pattern = email;
        rule.format = fm;
        fm.setFont(font);
        highlightingRules.append(rule);

}

void Highlighter::highlightBlock(const QString &text)
{
    for (const HighlightingRule &rule : std::as_const(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

}
