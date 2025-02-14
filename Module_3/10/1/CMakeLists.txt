cmake_minimum_required(VERSION 3.20)
project(staticLibProject)

set (PROJECT_NAME
staticLibProject
)

add_library(staticLib STATIC staticLib/Greeter.cpp staticLib/Greeter.h)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} staticLib)
