cmake_minimum_required(VERSION 3.20)
project(Light_Ricognition)

set(CMAKE_CXX_STANDARD 11)

#头文件所在地
include_directories(${PROJECT_SOURCE_DIR}/include)

#查找文件
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#生成可执行文件
add_executable(try ${MAIN_SRC})

#链接第三方库
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(try ${OpenCV_LIBS})