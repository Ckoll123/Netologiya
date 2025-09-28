cmake_minimum_required(VERSION 3.20)
project(HttpServer)

add_executable(${PROJECT_NAME}
                main.cpp
                HttpServer.cpp
                DBcontrol.cpp
                HttpServerFcns.cpp
)

link_directories(C:/msys64/ucrt64/lib)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    DOC_ROOT="${CMAKE_SOURCE_DIR}/server_data"
)

target_link_libraries(${PROJECT_NAME}
    pqxx
    pq
    boost_locale-mt
    ws2_32
    mswsock
)
