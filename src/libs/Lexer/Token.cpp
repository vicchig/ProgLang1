#include "../../inc/Token.h"

using std::to_string;

string Token::toString(bool indent){
    if(indent) return "    " + string("TEXT: ") + text + "\n    TYPE: " + tknTypeToStr.at(type) + "\n    LINE: " + to_string(lineNum) +  "\n    COL: " + to_string(column) + "\n    LEN: " + to_string(len);
    else return string("TEXT: ") + text + "\nTYPE: " + tknTypeToStr.at(type) + "\nLINE: " + to_string(lineNum) +  "\nCOL: " + to_string(column) + "\nLEN: " + to_string(len);
}