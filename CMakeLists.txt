cmake_minimum_required(VERSION 3.10)
project(RouteRecorder)

# Add the source files
add_subdirectory(arduino_code/gps_logger)

# Google Test
add_subdirectory(googletest)

enable_testing()

# Add the test files
add_executable(tests tests/sample_test.cpp)
target_link_libraries(tests gtest gtest_main)

add_test(NAME SampleTest COMMAND tests)
