include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(utility STATIC utility.cpp
    status.cc
)