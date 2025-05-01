#минимальная версия cmake
cmake_minimum_required(VERSION 3.10)
#имя проекта
project(demoVendorCatch2)
#добавляем поддиректорию, в которой будет catch2
#add_subdirectory(catch2)

include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.3.2
)
FetchContent_MakeAvailable(catch2)

#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(${PROJECT_NAME} main.cpp)
#линкуемся к catch2, в котором уже есть main
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)