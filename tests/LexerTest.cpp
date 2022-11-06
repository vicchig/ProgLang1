#include "../inc/Lexer.h"
#include "../inc/Token.h"
#include <vector>
#include <tuple>
#include <gtest/gtest.h>

using std::vector;
using std::tuple;

//tuple<string, vector<Token>>
class LexerTestParametrizedFixture :public ::testing::TestWithParam<tuple<string, vector<Token>>> {
protected:
    Lexer lex;
};

// Demonstrate some basic assertions.
TEST_P(LexerTestParametrizedFixture, LexerAcceptsBasicTokens) {
  tuple<string, vector<Token>> inputs = GetParam();
  lex.setFilePath(get<0>(inputs));
  vector<Token> actual = lex.tokenizeFile();
  vector<Token> expected = get<1>(inputs);
  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(
      LexerBasicTokensTests,
      LexerTestParametrizedFixture,
      ::testing::Values(
              tuple<string, vector<Token>>{
                "./TestPrograms/singleTokens.pl", 
                vector<Token>{
                  Token("#keywords#", COMMENT_TKN, 1, 1),
                  Token("if", KEYWORD_TKN, 2, 1)
                }
              }
      )
);