#include "../../inc/Tokenizer.h"

vector<Token> Tokenizer::tokenizeStr(string str, int lineNum){
    vector<Token> tkns{};
    bool done = false;

    char nextChar;
    int charCode;
    int nextState; 
    int tokenLen = 0;
    int offset = 0;
    while(!done && charIndex < str.length() && str.length() > 0){
        nextChar = str.at(charIndex);

        //NOTE: Cannot have all word chars in alphabet (too many), so strings and comments
        //require special handling
        if((state != 3 && state != 5) || nextChar == '"' || nextChar == '#'){
            charCode = alphabet.at(nextChar);
            nextState = transitionMatrix[state][charCode];
        } else{
            nextState = state;
        }

        //either accept the token or continue
        if(nextState == 30 || nextState == 40){
            tkns.push_back(constructTkn(str.substr(offset, tokenLen), lineNum, offset));
            offset += tokenLen;
            tokenLen = 0;
            state = 0;
        } else{
            state = nextState;
            tokenLen++;
            charIndex++;
        }

        //reached end of line
        if(charIndex >= str.length() && 
           (state == 1 || state == 2 || state == 4 || state == 6 || state == 7 || state == 9 ||
            state == 12 || state == 13 || state == 15 || state == 16 || 
            (state < 30 && state >= 17)
           )
        ){
            tkns.push_back(constructTkn(str.substr(offset, tokenLen), lineNum, offset));
            state = 0;
            charIndex = 0;  
            done = true;
        }
    }
    
    return tkns;
}


Token Tokenizer::constructTkn(string text, int lineNum, int columnStart){
    TokenType t = stateToTkn.contains(state) ? stateToTkn.at(state) : UNKNOWN_TKN;
    Token tkn = Token(text, t, lineNum, columnStart + 1); // columnStart is a string offset so starts at 0

    return tkn;
}
