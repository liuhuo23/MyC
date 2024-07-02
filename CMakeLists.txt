cmake_minimum_required(VERSION 3.10...3.21)
project(MyC VERSION 0.1.0 LANGUAGES CXX C) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

# libomp 15.0+ from brew is keg-only, so have to search in other locations.
# See https://github.com/Homebrew/homebrew-core/issues/112107#issuecomment-1278042927.

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
message("当前平台是 macos")
execute_process(COMMAND brew --prefix libomp
        OUTPUT_VARIABLE HOMEBREW_LIBOMP_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE)
set(OpenMP_C_FLAGS
        "-Xpreprocessor -fopenmp -I${HOMEBREW_LIBOMP_PREFIX}/include")
set(OpenMP_CXX_FLAGS
        "-Xpreprocessor -fopenmp -I${HOMEBREW_LIBOMP_PREFIX}/include")
set(OpenMP_C_LIB_NAMES omp)
set(OpenMP_CXX_LIB_NAMES omp)
set(OpenMP_C_INCLUDE ${HOMEBREW_LIBOMP_PREFIX}/include)
set(OpenMP_CXX_INCLUDE ${HOMEBREW_LIBOMP_PREFIX}/include)
set(OpenMP_omp_LIBRARY ${HOMEBREW_LIBOMP_PREFIX}/lib/libomp.dylib)
find_package(OpenMP REQUIRED)
find_package(CURL REQUIRED)
        elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
message("当前平台是Linux")
find_package(OpenMP REQUIRED)

endif()
set(ENV{SPDLOG_LEVEL} debug)
set(THIRDPARTY "thirdparty")
include_directories(${CMAKE_SOURCE_DIR}/include ${THIRDPARTY}/spdlog/include)
# 包含各个子目录
add_subdirectory(lib/utility)
add_subdirectory(lib/core)
add_subdirectory(app)
add_subdirectory(tests)
add_subdirectory(thirdparty/spdlog)
# This project is tested using GoogleTest.
add_subdirectory("thirdparty/googletest")