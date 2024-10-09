#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QObject>

class PrimeFinder : public QObject
{
    Q_OBJECT
public:
    explicit PrimeFinder(int n, int s, int e);

signals:
    void foundPrime(int thread, int prime);
    void finished();

public slots:
    void findPrimes();

private:
    bool isPrime(int toCheck);
    int startNum;
    int endNum;
    int threadNumber;
};

#endif // PRIMEFINDER_H
