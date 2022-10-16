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
