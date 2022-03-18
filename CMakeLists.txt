cmake_minimum_required(VERSION 3.0.0)
project(app VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(202104-1 202104-1.cpp)
add_executable(202109-1 202109-1.cpp)
add_executable(202112-1 202112-1.cpp)