project(examples)

add_executable(imgui_demo imgui_demo.cpp)
target_link_libraries(imgui_demo vis)

add_executable(vector_allign_tests vector_allign_tests.cpp)

add_executable(display_image display_image.cpp)
target_link_libraries(display_image vis cv)