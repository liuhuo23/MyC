#include <iostream>
#include "core/inc/core.h"
#include <omp.h>
#include "app.h"
#include <memory>
int main(int argc, char *argv[])
{
    std::cout << "hello" << std::endl;
    std::cout << add(1, 2) << std::endl;
    std::unique_ptr<MyInterface> test(new MyInterface());
    test->publicApi1();
    return 0;
}