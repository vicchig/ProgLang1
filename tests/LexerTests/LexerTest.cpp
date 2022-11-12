#include "../../src/inc/Lexer.h"
#include "../../src/inc/Token.h"
#include <vector>
#include <tuple>
#include <gtest/gtest.h>

using std::vector;
using std::tuple;
using std::cout;
using std::endl;

//tuple<string, vector<Token>>
class LexerTestParametrizedFixture :public ::testing::TestWithParam<tuple<string, vector<Token>>> {
protected:
    Lexer lex = Lexer();
};

// Demonstrate some basic assertions.
TEST_P(LexerTestParametrizedFixture, LexerAcceptsBasicTokens) {
  tuple<string, vector<Token>> inputs = GetParam();
  lex.setFilePath(get<0>(inputs));

  vector<Token> actual = lex.tokenizeFile();
  vector<Token> expected = get<1>(inputs);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_CASE_P(
      LexerBasicTokensTests,
      LexerTestParametrizedFixture,
      ::testing::Values(
              tuple<string, vector<Token>>{
                "singleTokens.pl", 
                vector<Token>{
                  Token("#keywords#", COMMENT_TKN, 1, 1),
                  Token("if", KEYWORD_TKN, 2, 1)
                }
              }
      )
);