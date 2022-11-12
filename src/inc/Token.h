#pragma once

#include <string>
#include <map>

using std::string;
using std::map;

enum TokenType{
    UNKNOWN_TKN,
    DECIMAL_TKN,
    INTEGER_TKN,
    KEYWORD_TKN,
    IDENTIFIER_TKN,
    WHITESPACE_TKN,
    COMMENT_TKN,
    PUNCTUATION_TKN,
    OPERATOR_TKN,
    STRING_TKN,
    UNKOWN_KEYWORD_TKN,
    UNKNOWN_IDENTIFIER_TKN,
    UNKNOWN_DECIMAL_FORMAT_TKN
};

const map<TokenType, string> tknTypeToStr {
    {UNKNOWN_TKN, "UKNOWN TOKEN"}, {DECIMAL_TKN, "DECIMAL TOKEN"}, {INTEGER_TKN, "INTEGER TOKEN"},
    {KEYWORD_TKN, "KEYWORD TOKEN"}, {IDENTIFIER_TKN, "IDENTIFIER TOKEN"}, {WHITESPACE_TKN, "WHITESPACE TOKEN"},
    {COMMENT_TKN, "COMMENT TOKEN"}, {PUNCTUATION_TKN, "PUNCTUATION TOKEN"}, {OPERATOR_TKN, "OPERATOR TOKEN"},
    {STRING_TKN, "STRING TOKEN"}, {UNKOWN_KEYWORD_TKN, "UNKNOWN KEYWORD TOKEN"}, {UNKNOWN_IDENTIFIER_TKN, "UNKNOWN IDENTIFIER TOKEN"},
    {UNKNOWN_DECIMAL_FORMAT_TKN, "UNKNOWN DECIMAL TOKEN"}
};

class Token{
    public:
        Token(string text = "", TokenType type = UNKNOWN_TKN, int lineNum = 1, int column = 1):text{text}, type{type}, lineNum{lineNum}, column{column}{
            len = text.length();
        };

        string toString(bool indent = false);
        auto operator<=>(const Token&) const = default;

        string text;
        TokenType type;
        int lineNum;
        int column;
        int len;
};