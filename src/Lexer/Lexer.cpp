#include "../../inc/Lexer.h"

vector<Token> Lexer::tokenizeFile(){
    vector<Token> tokens{};
    vector<Token> nextTokens = tokenizeLines(TOKENIZE_LINE_LIMIT);
    tokens.insert(tokens.end(), nextTokens.begin(), nextTokens.end());
    while(nextTokens.size() > 0){
        nextTokens = tokenizeLines(TOKENIZE_LINE_LIMIT);
        tokens.insert(tokens.end(), nextTokens.begin(), nextTokens.end());
    }

    return tokens;
}

vector<Token> Lexer::tokenizeLines(int linesToTokenize){
    vector<string> lines{};
    string line;
    int linesRead = 0;
     while(getline(codeFileHandle, line) && linesRead < linesToTokenize){
        lines.push_back(line);
    }

    vector<Token> tokens{};
   // int lineOffset = 0; //TODO: Remove comment later. Use these as offsets into current TOKENIZE_LINE_LIMIT window for tokenization
    //int columnOffset = 0;
    for(int i = 0; i < lines.size(); i++){
        vector<Token> lineTkns = tokenizeLine(lines.at(i));
        tokens.insert(tokens.end(), lineTkns.begin(), lineTkns.end());
    }

    return tokens;
}

vector<Token> Lexer::tokenizeLine(string line){
    vector<Token> tkns = tokenizer.tokenizeStr(line, currLine);
    currLine++;

    return tkns;
    //tokenize the line
    //update the currLine
    //col updates happen depending on length of token tokenized or where error occured so probably the state machine handles that
}

Lexer::~Lexer(){
    if(codeFileHandle.is_open()){
        codeFileHandle.close();
    }
}