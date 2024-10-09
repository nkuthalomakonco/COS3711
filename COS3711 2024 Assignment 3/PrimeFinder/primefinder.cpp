#include "primefinder.h"
#include <qmath.h>
#include <QThread>


PrimeFinder::PrimeFinder(int n, int s, int e)
: startNum(s), endNum(e), threadNumber(n)
{

}

void PrimeFinder::findPrimes()
{
    for (int count = startNum; count <= endNum; count++)
    {
        if (isPrime(count))
            emit foundPrime(threadNumber, count);
        QThread::msleep(1);
    }

    emit finished();
}

bool PrimeFinder::isPrime(int toCheck)
{
    if (toCheck % 2 == 0)
        return false;
    int sqtocheck = sqrt(toCheck) + 1;
    for (int i=3; i<= sqtocheck; i += 2)
        if (toCheck % i == 0)
            return false;
    return true;
}
