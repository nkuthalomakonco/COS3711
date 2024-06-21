#include "cd.h"

CD::CD()
{
    composer = "Unkown";
    rating = 0;
    cost = 0;
    albumName = "Unkown";
}

CD::CD(QString c, int r, double cst, QString alb)
{
    composer = c;
    rating = r;
    cost = cst;
    albumName = alb;
}

CD::~CD()
{

}

QString CD::toString() const
{
    return QString("Composer: "+ composer +" Album: " + albumName +
                   " Cost: " + QString::number(cost, 'f', 2) + " Rating: " + QString::number(rating));
}

QString CD::getComposer() const
{
    return composer;
}

void CD::setComposer(const QString &newComposer)
{
    composer = newComposer;
}

int CD::getRating() const
{
    return rating;
}

void CD::setRating(int newRating)
{
    rating = newRating;
}

double CD::getCost() const
{
    return cost;
}

void CD::setCost(double newCost)
{
    cost = newCost;
}

QString CD::getAlbumName() const
{
    return albumName;
}

void CD::setAlbumName(const QString &newAlbumName)
{
    albumName = newAlbumName;
}
