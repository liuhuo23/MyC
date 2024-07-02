#include <iostream>
#include "core/inc/core.h"
#include <omp.h>
#include "app.h"
#include <memory>
#include "status.h"
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"
#include <functional>
#include <typeinfo>
#define HANDLEFUN(func_name, ...) std::bind(func_name, ##__VA_ARGS__)
int add1(int i, int j, int k) { return i + j + k; }
class Utils {
public:
    Utils(const char* name) { strcpy(_name, name); }
    void sayHello(const char* name) const {
        std::cout << _name << " say: hello" << name << std::endl;
    }
    static int getId() { return 100001; }
    int operator()(int i, int j, int k) const { return i + j + k; }

private:
    char _name[32];
};

int handleFunc(std::function<int()> callback) { return callback(); }
int callback1(int x) {
    std::cout << "callback1 " << x << std::endl;
    return x;
}
int callbacl2(int x, int y) {
    std::cout << "callback2 " << x << " " << y << std::endl;
    return x + y;
}
int callback3(int x, const char* a) {
    std::cout << "x=" << x << " a" << a << std::endl;
    return 0;
}
int main(int argc, char* argv[]) {
    spdlog::set_level(spdlog::level::debug);
    spdlog::info("hello...");
    MyC::Status notfound = MyC::Status::NotFound(MyC::Slice("没有发现"), MyC::Slice("没有发现2"));
    std::cout << notfound.ToString() << std::endl;

    // 绑定全局函数
    auto add2 = std::bind(add1, std::placeholders::_1, std::placeholders::_2, 10);
    std::cout << typeid(add2).name() << std::endl;
    std::cout << "add2(1,2) = " << add2(1, 2) << std::endl;

    handleFunc(std::bind(callback1, 1));
    handleFunc(HANDLEFUN(callbacl2, 1, 2));
    char a[] = "hello world!";
    handleFunc(HANDLEFUN(callback3, 1, a));
    return 0;
}