#!/bin/bash
home_dir=$(dirname "$(realpath "$0")")
echo "当前脚本路径：${home_dir}"
git submodule init
git submodule update
cpus=$(nproc)
# 定义数组来存储子模块路径
export submodule_paths=()
# 定义 .gitmodules 文件的路径
GITMODULES_FILE="$(pwd)/.gitmodules"

# 检查 .gitmodules 文件是否存在
if [ ! -f "$GITMODULES_FILE" ]; then
    echo ".gitmodules 文件不存在"
    exit 1
fi

# 使用 grep 查找子模块路径
echo "列出所有子模块的路径："
# 读取 .gitmodules 文件并提取子模块路径
while IFS= read -r line; do
    # 使用正则表达式匹配 "path =" 后面的内容
    if [[ "$line" =~ path\ = ]]; then
        # 截取等号后的字符串，并去除可能的前后空白字符
        path="${line#*=}"
        path=$(echo "$path" | tr -d ' ')
        # 将子模块路径添加到数组
        submodule_paths+=("$path")
    fi
done < "$GITMODULES_FILE"
echo "第三方路径：${submodule_paths[@]}"
local_path="$home_dir/local"
echo "第三方库安装路径: ${local_path}"
# 检查 build 目录是否存在，不存在则创建
if [ ! -d ./build ]; then
    mkdir ${local_path}
fi
setup_oatpp() {
    # 检查是否提供了 oatpp 路径参数
    if [ $# -eq 0 ]; then
        echo "错误：未提供 第三方路径 路径。"
        return 1
    fi

    local third_path="$1" # 第一个参数是 oatpp 的路径
    local build_type="${BUILD_TYPE:-Debug}" # 使用环境变量 BUILD_TYPE，如果没有设置则默认为 Debug
    # 进入 oatpp 目录
    cd "./$third_path"
    echo $(pwd)
    # 检查 build 目录是否存在，不存在则创建
    if [ ! -d ./build ]; then
        mkdir ./build
    else
        rm -rf ./build
        mkdir ./build
    fi

    # 进入 build 目录
    cd ./build

    # 运行 CMake 配置
    cmake .. -DCMAKE_BUILD_TYPE="$build_type" -DCMAKE_INSTALL_PREFIX="$local_path" -DOATPP_SQLITE_AMALGAMATION=ON

    # 构建项目
    cmake --build . -j $cpus

    # 安装项目，如果需要 sudo 权限
    make install
    cd $home_dir
}
echo $submodule_paths
for item in "${submodule_paths[@]}";do
    echo "构建${item}"
    setup_oatpp "$item"
done
