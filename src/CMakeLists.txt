cmake_minimum_required(VERSION 3.23.2)

add_executable(PLCompiler Main.cpp)

add_subdirectory(libs)
target_link_libraries(PLCompiler PRIVATE Lexer)
