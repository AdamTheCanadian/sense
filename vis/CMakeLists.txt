cmake_minimum_required(VERSION 3.10)
project(vis)

add_subdirectory(submodules)

include_directories(include/)
add_library(${PROJECT_NAME} 
  src/display.cpp
  src/rgb_image_window.cpp
  )

target_link_libraries(${PROJECT_NAME} imgui cv glm)
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  include/
  submodules/glm)