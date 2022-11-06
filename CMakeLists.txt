cmake_minimum_required(VERSION 3.23.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(ProgLang1 VERSION 1.0)
add_executable(ProgLang1 ./src/Main.cpp)


add_subdirectory(./src/Lexer)
target_link_libraries(ProgLang1 PUBLIC Lexer)

add_subdirectory(./tests)
target_link_libraries(
  LexerTest
  GTest::gtest_main
  Lexer
)

configure_file(ProgLang1Config.h.in ProgLang1Config.h)
target_include_directories(ProgLang1 PUBLIC
                           "../inc"
                           "${PROJECT_BINARY_DIR}"
                           )

# run cmake from build dir and pass path to CMakeLists.txt file (can add --fresh flag)
# run cmake --build ./ from build dir