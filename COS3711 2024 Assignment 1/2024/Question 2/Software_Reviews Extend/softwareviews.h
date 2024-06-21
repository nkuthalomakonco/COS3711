#ifndef SOFTWAREVIEWS_H
#define SOFTWAREVIEWS_H

#include <QObject>
#include <QDate>

class softwareviews: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)
    Q_PROPERTY(bool recommended READ getRecommended WRITE setRecommended)

public:
    softwareviews();
    softwareviews(QString,QDate,bool);
    ~softwareviews();
    QString toString()const;

    QString getName() const;
    void setName(const QString &newName);

    QDate getDate() const;
    void setDate(const QDate &newDate);

    bool getRecommended() const;
    void setRecommended(bool newRecommended);

private:
    QString name;
    QDate date;
    bool recommended;
};

#endif // SOFTWAREVIEWS_H
