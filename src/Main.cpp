#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "ProgLang1Config.h"
#include "../inc/Lexer.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;


int main(int argc, char* argv[])
{
    Lexer l = Lexer();
    //make sure file name arg is present
    if (argc < 2) {
        cout << "Missing file argument.\nUse ProgLang1.exe <FileName.pl1>";
        return 1;
    }

    //save filename before manipulation
    char* fileName = (char*)malloc(sizeof(char) * (strlen(argv[1]) + 1));
    if (fileName == NULL) {
        cout << "Malloc fail." << endl;
        return 1;
    }
    strcpy_s(fileName, sizeof(char) * (strlen(argv[1]) + 1), argv[1]);

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

    //get all lines in the code
    ifstream codeFile;
    codeFile.open(fileName);

    string line;
    vector<string> lines{};
    while (getline(codeFile, line)) {
        lines.push_back(line);
    }


    //cleanup
    free(fileName);
    codeFile.close();

    return 0;
}

