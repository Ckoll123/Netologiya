cmake_minimum_required(VERSION 3.20)
project(Final_Project)

add_executable(${PROJECT_NAME}
                main.cpp
                DBcontrol.cpp
                IniParser.cpp
                Indexer.cpp
                HttpClient.cpp
                HttpServer.cpp
                HttpServerFcns.cpp
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    DOC_ROOT="${CMAKE_SOURCE_DIR}/server_data"
)

configure_file(${CMAKE_SOURCE_DIR}/configurator.ini
               ${CMAKE_BINARY_DIR}/configurator.ini
               COPYONLY)

# link_directories(C:/msys64/ucrt64/lib)

find_package(Boost REQUIRED COMPONENTS locale)
find_package(PostgreSQL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)


target_include_directories(${PROJECT_NAME} PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${PostgreSQL_INCLUDE_DIRS}
    ${PQXX_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${PostgreSQL_LIBRARIES}
    ${PQXX_LIBRARIES}
    ws2_32
    mswsock
)


# target_link_libraries(${PROJECT_NAME}
#     pqxx
#     pq
#     boost_locale-mt
#     ws2_32
#     mswsock
# )
