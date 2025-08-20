cmake_minimum_required(VERSION 3.10)
project(Amortizer VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Main Application
add_executable(amortizer
    main.cpp
    src/menu.cpp
    src/login.cpp
    src/user.cpp
    src/loan.cpp
    src/settings.cpp
    src/utils.cpp
)

# Logging for main application
find_package(Glog REQUIRED)
target_link_libraries(amortizer glog)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test Runner
add_executable(test_runner
    test/test_user.cpp
    test/test_loan.cpp
    test/test_utils.cpp
    src/user.cpp
    src/loan.cpp
    src/utils.cpp
)

target_include_directories(test_runner PRIVATE include)
target_link_libraries(test_runner gtest gtest_main pthread glog)

# Optional: Enable `ctest` support
enable_testing()
add_test(NAME AllTests COMMAND test_runner)
