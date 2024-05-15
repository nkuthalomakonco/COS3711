#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
    public:
        static Singleton * getInstance();
    private:
        Singleton();
        static Singleton * instance;
};

#endif // SINGLETON_H
