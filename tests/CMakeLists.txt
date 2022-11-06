cmake_minimum_required(VERSION 3.23.2)

# Vars
set(This TestMain)
set(Sources
    ./LexerTests/LexerTest.cpp
)

# Create main test executable and link it with googletest and items being tested
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Lexer
)

# exposes test to googletest
add_test(
    NAME ${This}
    COMMAND ${This}
)