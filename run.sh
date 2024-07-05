##########################################################################
# File Name: run.sh
# Author: 
# mail: 
# Created Time: 2024年07月03日 星期三 00时28分35秒
#########################################################################
#!/bin/zsh
PATH=/home/edison/bin:/home/edison/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/work/tools/gcc-3.4.5-glibc-2.3.6/bin
export PATH

echo "开始编译..."
cd build
cores=${nprpc}
ninja -t clean && ninja -j "$cores" $1
echo "开始运行。。。"
./app/$1
