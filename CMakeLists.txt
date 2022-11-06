cmake_minimum_required(VERSION 3.23.2)

# CMake config
set(CMAKE_CXX_STANDARD 20) # C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing() # let's cmake know project will include tests 

project(PLCompiler VERSION 1.0)

add_subdirectory(src)
add_subdirectory(tests)


# run cmake from build dir and pass path to CMakeLists.txt file (can add --fresh flag)
# run cmake --build ./ from build dir

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)