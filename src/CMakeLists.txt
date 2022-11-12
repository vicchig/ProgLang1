cmake_minimum_required(VERSION 3.23.2)

add_executable(PLCompiler Main.cpp)

add_subdirectory(libs)
target_link_libraries(PLCompiler PRIVATE Lexer)


# To run
# 1. cmake --fresh <path to main CMakeLists.txt> (run from build dir)
# 2. cmake --build <path to build dir>

# To test
# 1. ctest -j10 -C Debug -T test --output-on-failure

# To add a library
# 1. Add library folder to ./libs
# 2. Create library from sources in ./libs/CMakeLists
# 3. Link library to main project executable in main CMakeLists

# To add a test
# 1. Create test in ./tests/TestFolderName
# 2. Add test executable and link it with gtest_main and items being tested in ./tests/CMakeLists
# 3. Add test to google tests in ./tests/CMakeLists