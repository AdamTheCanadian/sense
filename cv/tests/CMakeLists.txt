project(cv_tests)


if(CMAKE_TESTING_ENABLED)
  # Requires GTEST for running unit tests
  find_package(GTest REQUIRED)
  include_directories(${GTEST_INCLUDE_DIRS})
  add_executable(
    ${PROJECT_NAME}
    cv_tests.cpp
    image_tests.cpp
    io_tests.cpp
    )
  
  # Set a compile time constant of the repo path so we can load files for tests
  # This lets us get the full path /username/documents/.... and so we can easily
  # find the test images
  add_definitions(-DBUILD_PATH="${CMAKE_SOURCE_DIR}")
  target_link_libraries(
    ${PROJECT_NAME}
    cv
    ${GTEST_LIBRARIES}
    pthread)
  
  set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
  
  add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME})
  
  # This command will run the unit tests as part of the build
  add_custom_command(
    TARGET ${PROJECT_NAME}
    COMMENT "Run tests"
    POST_BUILD 
    COMMAND ${PROJECT_NAME})
            
endif()