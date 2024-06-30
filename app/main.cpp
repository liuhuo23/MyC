#include <iostream>
#include "core/inc/core.h"
#include <omp.h>
int main(int argc, char *argv[])
{
    std::cout << "hello" << std::endl;
    std::cout << add(1, 2) << std::endl;
    return 0;
}