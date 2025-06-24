cmake_minimum_required(VERSION 3.20)
project(MyWtProject)

set(CMAKE_CXX_STANDARD 17)

set(WT_ROOT "C:/msys64/mingw64")

include_directories(${WT_ROOT}/include)
link_directories(${WT_ROOT}/lib)

add_executable(MyWtProject main.cpp)


target_link_libraries(MyWtProject PRIVATE
    wtdbo
    wtdbopostgres
)

