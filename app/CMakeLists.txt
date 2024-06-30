add_executable(myapp main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/lib ${OpenMP_CXX_INCLUDE})
target_link_libraries(myapp utility core CURL)