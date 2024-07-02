#ifndef TIRE_H
#define TIRE_H
#include <cstring>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>
namespace MyC {
struct Node {
    std::string pattern;
    std::string part;
    std::vector<std::unique_ptr<Node>> children;
    bool isWild;
};
using NodeP = std::unique_ptr<Node>;
using NodeMap = std::unordered_map<std::string, NodeP>;
using HandlerFunc = std::function<void()>;
class Router {
private:
    NodeMap roots;
    std::unordered_map<std::string, HandlerFunc> handles;
};
};  // namespace MyC
#endif