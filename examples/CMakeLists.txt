project(examples)

add_executable(imgui_demo imgui_demo.cpp)
target_link_libraries(imgui_demo vis)

add_executable(vector_allign_tests vector_allign_tests.cpp)