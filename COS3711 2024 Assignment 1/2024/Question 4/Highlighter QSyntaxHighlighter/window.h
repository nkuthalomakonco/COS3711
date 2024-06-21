#ifndef WINDOW_H
#define WINDOW_H

#include "highlighter.h"

#include <QWidget>

class QPushButton;
class QTextEdit;

class window : public QWidget
{
    Q_OBJECT

public:
    window(QWidget *parent = nullptr);
    ~window();

public slots:
    void loadFile(const QString &path = QString());
    void processSlots();

private:
    void setUpGui();

    QPushButton *PushButtonLoad;
    QPushButton *PushButtonProcess;
    QTextEdit *TextEdit;
    Highlighter *highlighter;
};

#endif // WINDOW_H
