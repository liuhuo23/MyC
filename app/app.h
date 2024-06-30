#ifndef APP_H
#define APP_H
#include <string>
#include <list>

class MyInterface
{
public:
    MyInterface();
    ~MyInterface();

    int publicApi1();
    int publicApi2();

private:
    struct Impl;
    Impl *pimpl_;
};

#endif
