add_executable(app main.cpp app.cpp)
set(ENV{SPDLOG_LEVEL} debug)
include_directories(${CMAKE_SOURCE_DIR}/lib ${OpenMP_CXX_INCLUDE})
# set(CMAKE_CXX_FLAGS "-framework Cocoa")
target_link_libraries(app utility core curl spdlog)
