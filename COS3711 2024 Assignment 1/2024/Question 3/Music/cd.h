#ifndef CD_H
#define CD_H

#include <QString>

class CD
{
public:
    CD();
    CD(QString composer,int rating,double cost,QString albumName);
    ~CD();
    QString toString()const;


    QString getComposer() const;
    void setComposer(const QString &newComposer);

    int getRating() const;
    void setRating(int newRating);

    double getCost() const;
    void setCost(double newCost);

    QString getAlbumName() const;
    void setAlbumName(const QString &newAlbumName);

private:
    //data members
    QString composer;
    int rating;
    double cost;
    QString albumName;//
};

#endif // CD_H
