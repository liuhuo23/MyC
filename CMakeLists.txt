cmake_minimum_required(VERSION 3.29.0)
project(MyC VERSION 0.1.0 LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 11)
find_package(CURL REQUIRED)
# libomp 15.0+ from brew is keg-only, so have to search in other locations.
# See https://github.com/Homebrew/homebrew-core/issues/112107#issuecomment-1278042927.
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
include_directories(${CMAKE_SOURCE_DIR}/include)
# 包含各个子目录
add_subdirectory(lib/utility)
add_subdirectory(lib/core)
add_subdirectory(app)
add_subdirectory(tests)
add_subdirectory(thirdparty/spdlog)