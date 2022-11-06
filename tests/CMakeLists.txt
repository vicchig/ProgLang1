cmake_minimum_required(VERSION 3.23.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Tests VERSION 1.0)

include(FetchContent)
FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# The below configuration enables testing in CMake, declares the C++ test binary you want to build (test), and links it to 
# GoogleTest (gtest_main). The last two lines enable CMake’s test runner to discover the tests included in the binary, using the 
# GoogleTest CMake module.
enable_testing()

add_executable(
  LexerTest
  ./LexerTest.cpp
)

include(GoogleTest)
gtest_discover_tests(LexerTest)

