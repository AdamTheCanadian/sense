cmake_minimum_required(VERSION 3.10)
project(cv)

set(CMAKE_CXX_STANDARD 14)

include_directories(include/)
# Interface only at this point since there are no CPP files
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include/)
target_link_libraries(${PROJECT_NAME} INTERFACE core)

enable_testing()
add_subdirectory(tests)