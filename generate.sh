##########################################################################
# File Name: run.sh
# Author: 
# mail: 
# Created Time: 2024年07月03日 星期三 00时28分35秒
#########################################################################
#!/bin/zsh
PATH=/home/edison/bin:/home/edison/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/work/tools/gcc-3.4.5-glibc-2.3.6/bin
export PATH
echo "清理生成"
cmake --build build/ --target clean
rm -rf build
mkdir build
echo "开始构建"
cmake -G Ninja -S . -B build  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
