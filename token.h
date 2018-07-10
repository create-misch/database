#pragma once

#include <sstream>
#include <vector>
using namespace std;

enum class LogicalOperation {
    And,
    Or
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class TokenType {
  DATE,
  EVENT,
  COLUMN,
  LOGICAL_OP, // AND OR
  COMPARE_OP, // < >
  PAREN_LEFT,
  PAREN_RIGHT,
};

struct Token {
  const string value;
  const TokenType type;
};

vector<Token> Tokenize(istream& cl);
