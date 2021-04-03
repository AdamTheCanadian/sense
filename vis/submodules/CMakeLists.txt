cmake_minimum_required(VERSION 3.10)
project(vis_submodules)

# Open GL is required for rendering images and the GUI windows to the screen
find_package(OpenGL REQUIRED)

set(GLFW_BUILD_EXAMPLES ON)
# GLFW is a library required that actually provides the window rendering functionality (but uses open gl) 
add_subdirectory(glfw)
add_subdirectory(glad)

# Files that import glfw import GLFW/*** so we need to include up to just before the GLFW/
include_directories(glfw/include)
include_directories(glad/include)

# imgui and implot do not have a library, meant to be included as part of one, so we will
# create a library. Also they are technically separate repos but will make one library 
# called imgui for the rest of the application to include (since implot needs imgui)
set(IMGUI_LIB imgui)
add_library(${IMGUI_LIB}
  imgui/imconfig.h
  imgui/imgui.cpp
  imgui/imgui.h
  imgui/imgui_demo.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_internal.h
  imgui/imgui_widgets.cpp
  imgui/imstb_rectpack.h
  imgui/imstb_textedit.h
  imgui/imstb_truetype.h
  imgui/imgui_tables.cpp
  imgui/backends/imgui_impl_glfw.cpp
  imgui/backends/imgui_impl_opengl3.cpp
  imgui/examples/libs/gl3w/GL/gl3w.c
  implot/implot.cpp
  implot/implot_demo.cpp
  implot/implot.h
  implot/implot_internal.h
  implot/implot_items.cpp)

target_link_libraries(${IMGUI_LIB} ${OPENGL_gl_LIBRARY} glfw glad)
# Tell IMGUI to use the GLAD implementation
target_compile_definitions(${IMGUI_LIB} PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)
target_include_directories(
  ${IMGUI_LIB}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui
  ${CMAKE_CURRENT_SOURCE_DIR}/implot
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples/libs/gl3w
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui/examples/libs/gl3w
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/)