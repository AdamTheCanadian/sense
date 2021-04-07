cmake_minimum_required(VERSION 3.10)
project(cv)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)
# Interface only at this point since there are no CPP files
add_library(${PROJECT_NAME}
  src/io.cpp
  src/image_file_store.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES 
  CXX_STANDARD 17)  
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} core)

enable_testing()
add_subdirectory(tests)