cmake_minimum_required(VERSION 3.23.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(ProgLang1 VERSION 1.0)

include_directories(
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Lexer/*.cpp
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/inc/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Lexer/*.cpp"
        )

add_executable(ProgLang1 ${all_SRCS})

configure_file(ProgLang1Config.h.in ProgLang1Config.h)
target_include_directories(ProgLang1 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

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
  ./tests/LexerTest.cpp
)
target_link_libraries(
  LexerTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(LexerTest)
