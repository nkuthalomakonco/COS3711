#include "widget.h"
#include <QPushButton>
#include <QSpinBox>
#include <QPlainTextEdit>
#include <QFormLayout>
#include <QLayout>
#include <QLabel>
#include <QGroupBox>

#include "primefinder.h"
#include <QThread>

Widget::Widget(QWidget *parent)
    : QWidget(parent),m_startNo{new QSpinBox()},m_endNo{new QSpinBox()},m_results{new QLabel},
    m_numberOfThreads{new QSpinBox()},m_start{new QPushButton("start")},m_displayWindow1{new QPlainTextEdit()},
    m_displayWindow2{new QPlainTextEdit()},m_displayWindow3{new QPlainTextEdit()},m_displayWindow4{new QPlainTextEdit()}
{
    setupUi();
    connect(m_start, SIGNAL(clicked()), this, SLOT(startThreads()));
}

Widget::~Widget() {qDeleteAll(threadList);}

void Widget::closeEvent(QCloseEvent *event)
{
    if (activeThreads != 0)
    {
        if (threadList.size()!= 0)
        {
            for (int i = 0; i < threadList.size(); i++)
            {
                threadList.at(i)->quit();
                threadList.at(i)->wait();
            }

            qDeleteAll(threadList);
            threadList.clear();
        }
    }
    event->accept();
}

void Widget::startThreads()
{
    activeThreads = m_numberOfThreads->value();
    if(activeThreads == 0)return;
    m_start->setEnabled(false);
    m_results->setText("");
    m_displayWindow1->clear();m_displayWindow2->clear();m_displayWindow3->clear();m_displayWindow4->clear();


    int begin(m_startNo->value());
    int end(m_endNo->value());

    int spread((end - begin) + 1);
    int increment( spread / activeThreads);

    int currentStart(begin);
    int currentEnd(currentStart + increment);

    m_timer.start();
    for (int i = 0; i < activeThreads; i++)
    {
        QThread *thread(new QThread);
        PrimeFinder *pf;

        // Calculate range for each worker, and instantiate
        if (i == activeThreads-1) // last thread searches to end
            pf = new PrimeFinder(i, currentStart, end);
        else
            pf = new PrimeFinder(i, currentStart, currentEnd);

        // Move worker to thread
        pf->moveToThread(thread);

        connect(thread, SIGNAL(started()), pf, SLOT(findPrimes()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), this, SLOT(threadDone()));

        connect(pf, SIGNAL(foundPrime(int,int)), this, SLOT(displayPrime(int,int)));
        connect(pf, SIGNAL(finished()), thread, SLOT(quit()));
        connect(pf, SIGNAL(finished()), pf, SLOT(deleteLater()));

        // Add to threadList
        threadList.append(thread);

        // Start thread
        thread->start();

        // Update for next thread
        currentStart = currentEnd + 1;
        currentEnd += increment;
    }m_start->setFocus();
}

void Widget::displayPrime(int thread, int p)
{
    switch (thread)
    {
    case 0 : m_displayWindow1->appendPlainText(QString::number(p)); break;
    case 1 : m_displayWindow2->appendPlainText(QString::number(p)); break;
    case 2 : m_displayWindow3->appendPlainText(QString::number(p)); break;
    case 3 : m_displayWindow4->appendPlainText(QString::number(p));
    }
}

void Widget::threadDone()
{
    activeThreads--;
    if (activeThreads == 0)
    {
        m_start->setEnabled(true);
        qDebug() << m_timer.elapsed();
        m_results->setText(QString("Time: %1 miliseconds").arg(m_timer.elapsed()));
    }
}

void Widget::setupUi()
{
    setWindowTitle("PrimeFinder");
    QVBoxLayout *layout = new QVBoxLayout(this);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow(tr("Start number"), m_startNo);m_startNo->setFixedSize(QSize(70,20));m_startNo->setRange(0,10000);
    formLayout->addRow(tr("End number"), m_endNo);m_endNo->setFixedSize(QSize(70,20));m_endNo->setRange(0,10000);
    formLayout->addRow(tr("Number of threads"), m_numberOfThreads);m_numberOfThreads->setFixedSize(QSize(70,20));m_numberOfThreads->setRange(0,4);
    m_startNo->setValue(1);m_endNo->setValue(100);m_numberOfThreads->setValue(2);
    QGroupBox *GroupBox = new QGroupBox(tr(""));
    GroupBox->setLayout(formLayout);

    layout->addWidget(GroupBox);
    layout->addWidget(m_start);

    QVBoxLayout *vlayout1 = new QVBoxLayout(0);
    vlayout1->addWidget(new QLabel(tr("Thread 1 results")));
    vlayout1->addWidget(m_displayWindow1);

    QVBoxLayout *vlayout2 = new QVBoxLayout(0);
    vlayout2->addWidget(new QLabel(tr("Thread 2 results")));
    vlayout2->addWidget(m_displayWindow2);

    QVBoxLayout *vlayout3 = new QVBoxLayout(0);
    vlayout3->addWidget(new QLabel(tr("Thread 3 results")));
    vlayout3->addWidget(m_displayWindow3);

    QVBoxLayout *vlayout4 = new QVBoxLayout(0);
    vlayout4->addWidget(new QLabel(tr("Thread 4 results")));
    vlayout4->addWidget(m_displayWindow4);

    QHBoxLayout *hlayout = new QHBoxLayout(0);
    hlayout->addLayout(vlayout1);
    hlayout->addLayout(vlayout2);
    hlayout->addLayout(vlayout3);
    hlayout->addLayout(vlayout4);

    layout->addLayout(hlayout);
    layout->addWidget(m_results);

    resize(250,400);
}
