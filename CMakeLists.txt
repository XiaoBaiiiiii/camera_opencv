cmake_minimum_required(VERSION 3.5)

project(FisheyeCamera)

# 查找 OpenCV 库
find_package(OpenCV REQUIRED)

# 添加可执行文件
add_executable(FisheyeCamera main.cc)

# 链接 OpenCV 库
target_link_libraries(FisheyeCamera ${OpenCV_LIBS})
