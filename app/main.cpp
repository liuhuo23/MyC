#include <iostream>
#include "core/inc/core.h"
#include <omp.h>
#include "app.h"
#include <memory>
#include "status.h"
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"
int main(int argc, char *argv[]) {
    spdlog::set_level(spdlog::level::debug);
    spdlog::info("hello...");
    MyC::Status notfound = MyC::Status::NotFound(MyC::Slice("没有发现"), MyC::Slice("没有发现2"));
    std::cout << notfound.ToString() << std::endl;
    return 0;
}