#include <iostream>
#include <string>
#include <vector>
#include "../inc/ProgLang1Config.h"
#include "../inc/Lexer.h"
#include "../inc/Token.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::to_string;


int main(int argc, char* argv[])
{
    //make sure file name arg is present
    if (argc < 2) {
        cout << "Missing file argument.\nUse ProgLang1.exe <FileName.pl1>";
        return 1;
    }

    //save filename before manipulation
    string codeFileName = argv[1];

    //check file extension
    char* nextToken = NULL;
    char* token = strtok_s(argv[1], ".", &nextToken);
    if (token != NULL) token = strtok_s(NULL, ".", &nextToken);

    if (token != NULL && strcmp("pl", token) == 1) {
        cout << "Wrong file extension\n\nExpected: .pl\nReceived: ." << token << endl;
        return 1;
    }
    else if(token == NULL) {
        cout << "Error reading file extension." << endl;
        return 1;
    }

    // SEND FILE TO LEXER
    Lexer lex = Lexer(codeFileName);
    vector<Token> tkns = lex.tokenizeFile();
    cout << tkns.size();
    for(int i = 0; i < tkns.size(); i++){
        cout << "TOKEN: " + to_string(i) << endl;
        cout << tkns.at(i).toString(true) << endl;
    }

    //get all lines in the code
    /*ifstream codeFile;
    codeFile.open(fileName);

    string line;
    vector<string> lines{};
    while (getline(codeFile, line)) {
        lines.push_back(line);
    }

    //TODO: TESTING CODE REMOVE LATER
    for(int i = 0; i < lines.size(); i++){
        cout << lines.at(i) << endl;
    }*/

    // 

    return 0;
}

