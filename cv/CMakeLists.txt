cmake_minimum_required(VERSION 3.10)
project(cv)

set(CMAKE_CXX_STANDARD 14)


include_directories(include/)
add_library(${PROJECT_NAME} INTERFACE)

# set_target_properties(${PROJECT_NAME} PROPERTIES 
#   LINKER_LANGUAGE CXX
#   CXX_STANDARD 14)
target_include_directories(${PROJECT_NAME} INTERFACE include/)

enable_testing()
add_subdirectory(tests)