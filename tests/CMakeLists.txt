cmake_minimum_required(VERSION 3.23.2)

# Vars
set(LexerSources
    ./LexerTests/LexerTest.cpp
)

# Create main test executable and link it with googletest and items being tested
add_executable(LexerTests ${LexerSources})
target_link_libraries(LexerTests PUBLIC
    gtest_main
    Lexer
)

# exposes test to googletest
add_test(
    NAME LexerTests
    COMMAND LexerTests
)
