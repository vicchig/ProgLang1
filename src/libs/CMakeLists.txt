cmake_minimum_required(VERSION 3.23.2)

add_library(Lexer
            STATIC
            "${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Lexer.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Token.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/Lexer/Tokenizer.cpp"
)
