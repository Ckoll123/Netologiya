cmake_minimum_required(VERSION 3.20)
project(dynamicLibProject)

set (PROJECT_NAME
dynamicLibProject
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(dynamicLib SHARED DynamicLib/Leaver.cpp DynamicLib/Leaver.h)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} dynamicLib)
