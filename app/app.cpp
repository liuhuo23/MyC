#include "app.h"

struct MyInterface::Impl
{
    int publicApi1();
    int publicApi2();

    int privateMethod1();
    std::string name_;
    std::list<int> list_;
};

MyInterface::MyInterface()
    : pimpl_(new Impl())
{
}

MyInterface::~MyInterface()
{
    delete pimpl_;
}

int MyInterface::publicApi1()
{
    return pimpl_->publicApi1();
}

int MyInterface::publicApi2()
{
    return pimpl_->publicApi2();
}

int MyInterface::Impl::publicApi1()
{
    printf("接口1");
    return 0;
}

int MyInterface::Impl::publicApi2()
{
    printf("接口2");
    return 0;
}