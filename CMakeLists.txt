cmake_minimum_required(VERSION 3.10)
project(RouteRecorder)

# Add the source files
add_subdirectory(arduino_code/gps_logger)
# Include directories
include_directories(arduino_code/gps_logger)
include_directories(src tests/mocks)

# Google Test
add_subdirectory(googletest)

enable_testing()

# Add the test files
add_executable(tests tests/helper_test.cpp arduino_code/gps_logger/Helper.cpp tests/mocks/MockArduino.cpp)
target_link_libraries(tests gtest gtest_main)

add_test(NAME SampleTest COMMAND tests)
