cmake_minimum_required(VERSION 3.23.2)

set(This TestMain)
set(Sources
    ./LexerTests/LexerTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Lexer
)

add_test(
    NAME ${This}
    COMMAND ${This}
)