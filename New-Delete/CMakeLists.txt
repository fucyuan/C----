# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(MyProject VERSION 1.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含 include 目录
include_directories(include)

# 查找源文件并将其添加到可执行文件
file(GLOB SOURCES "src/*.cpp")

# 定义生成的可执行文件
add_executable(MyProject ${SOURCES})

# 可选：为目标添加额外的编译器标志
# target_compile_options(MyProject PRIVATE -Wall -Wextra -pedantic)

# 可选：为项目添加测试（如果需要）
# enable_testing()


# # 设置 CMake 最低版本要求
# cmake_minimum_required(VERSION 3.10)

# # 设置项目名称和版本
# project(ProjectName VERSION 1.0)

# # 设置 C++ 标准
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # 可选：设置编译类型（Debug, Release, etc.）
# # 默认情况下是 Debug，也可以通过命令行 -DCMAKE_BUILD_TYPE=Release 覆盖
# set(CMAKE_BUILD_TYPE Debug)

# # 可选：设置编译选项（根据需要调整）
# # add_compile_options(-Wall -Wextra -pedantic)

# # 可选：将头文件目录添加到包含路径
# include_directories(include)

# # 查找源文件
# # 自动查找 src 目录下的所有 .cpp 文件
# file(GLOB_RECURSE SOURCES "src/*.cpp")

# # 添加可执行目标
# add_executable(${PROJECT_NAME} ${SOURCES})

# # 可选：如果有多个目标，可以分别设置
# # add_executable(TargetName src/main.cpp)

# # 可选：为目标设置链接库
# # target_link_libraries(${PROJECT_NAME} PUBLIC SomeLibrary)

# # 可选：添加子目录（用于大型项目）
# # add_subdirectory(submodule)

# # 可选：安装配置（将生成的文件安装到系统目录）
# # install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# # 可选：设置单元测试
# # enable_testing()
# # add_subdirectory(tests)

# # 输出项目配置信息
# message(STATUS "CMake project: ${PROJECT_NAME}")
# message(STATUS "CMake build type: ${CMAKE_BUILD_TYPE}")
