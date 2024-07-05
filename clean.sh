#/bin/sh
home_dir=$(dirname "$(realpath "$0")")
echo "当前脚本路径：${home_dir}"
git submodule init
git submodule update
local_path="$home_dir/local"
echo "第三方库安装路径: ${local_path}"
rm -rf ${local_path}