#include <stdio.h>
#include "core/inc/core.h"
#include "utility/inc/utility.h"
#include <iostream>
#include <assert.h>
#include <math.h>
#include "threadPool.hpp"
#include <spdlog/spdlog.h>

int main()
{
    spdlog::info("stat test...");
    std::cout << MyC::get_xunhuan(100012312312, 9) << std::endl;
    assert(MyC::get_xunhuan(100012312312, 9) == 7);
    assert(add(1, 2) == 3);
    assert(MyC::get_xunhuan(3, 3) == 0);
    assert(MyC::get_xunhuan(2, 10) != 9);
    ThreadPool pool(4);
    std::vector<std::future<int>> results;
    for (int i = 0; i < 8; i++)
    {
        results.emplace_back(
            pool.enqueue([i]
                         {
            std::cout << "hello" << i << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout<<"word" << i << std::endl;
            return i*i; }));
    }
    for (auto &&result : results)
    {
        std::cout << result.get() << " ";
    }
    std::cout << std::endl;
}