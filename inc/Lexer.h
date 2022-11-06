#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <string>

#include "Token.h"
#include "Tokenizer.h"

using std::ifstream;
using std::string;
using std::vector;

class Lexer
{
	public:
		Lexer(string codeFileName = ""):currLine{1}, currCol{1}, filePath{codeFileName}{
			codeFileHandle.open(filePath);
		};
		~Lexer();

		vector<Token> tokenizeFile();
		void setFilePath(string newPath);

	private:
		const int TOKENIZE_LINE_LIMIT = 10;

		int currLine;
		int currCol;
		string filePath;
		ifstream codeFileHandle;
		vector<Token> tokenizeLines(int linesToTokenize);
		vector<Token> tokenizeLine(string line);
		Tokenizer tokenizer{};
};

