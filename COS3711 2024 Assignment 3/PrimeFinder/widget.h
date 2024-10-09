#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QElapsedTimer>

class QSpinBox;
class QPushButton;
class QPlainTextEdit;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void closeEvent(QCloseEvent *);
public slots:
    void startThreads();
    void displayPrime(int thread, int p);
    void threadDone();
private:
    void setupUi();
    QSpinBox *m_startNo;
    QSpinBox *m_endNo;
    QSpinBox *m_numberOfThreads;
    QPushButton *m_start;
    QPlainTextEdit *m_displayWindow1;
    QPlainTextEdit *m_displayWindow2;
    QPlainTextEdit *m_displayWindow3;
    QPlainTextEdit *m_displayWindow4;
    QElapsedTimer m_timer;
    QLabel *m_results;

    QList<QThread*> threadList;
    int activeThreads;
};
#endif // WIDGET_H
