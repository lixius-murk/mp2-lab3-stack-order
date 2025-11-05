#include <iostream>
#include "token.h"
#include "operations.h"
#include "operands.h"

namespace std;
class LexEvaluation {
    std::string expression;
    size_t pos;

    void skipSpace() {
        while (pos < expression.length() && isspace(expression[pos])) {
            pos++;
        }
    }

    bool isDigit(char c) {
        return isdigit(c) || c == '.';
    }

    std::string readNumber() {
        size_t start = pos;
        while (pos < expression.length() &&
            (isdigit(expression[pos]) || expression[pos] == '.')) {
            pos++;
        }
        std::string numStr = expression.substr(start, pos - start);
        return numStr;
    }


public:
    Lexer(const std::string& expr) : expression(expr), pos(0) {}

    std::queue<Token> tokenize() {
        std::queue<Token>  tokens;
        bool expectOperand = true;

        while (pos < expression.length()) {
            skipSpace();
            if (pos >= expression.length()) break;

            char cur = expression[pos];

            if (isDigit(cur)) {
                tokens.push(readNumber());
                expectOperand = false;
            }
            else if (current == '(') {
                tokens.push(new Bracket(true));
                expectOperand = true;
                pos++;
            }
            else if (cur == ')') {
                tokens.push(new Bracket(false));
                expectOperand = false;
                pos++;
            }
            else if (cur == '+') {
                tokens.push(new Add());
                expectOperand = true;
                pos++;
            }
            else if (cur == '-') {
                if (expectOperand) {
                    tokens.push(new Operands(0) < int > );
                }
                tokens.push(new Sub());
                expectOperand = true;
                pos++;
            }
            else if (cur == '*') {
                tokens.push(new Mult());
                expectOperand = true;
                pos++;
            }
            else if (cur == '/') {
                tokens.push(new Div());
                expectOperand = true;
                pos++;
            }
            else {
                throw std::runtime_error("Неизвестный символ!");
            }
        }

        return tokens;
    }
};