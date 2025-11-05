#include<iostream>


enum TokenType {
    OPEN_BRACKET, CLOSE_BRACKET ADD, SUB, MULT, DIV, OPERAND
};
class Token {
public:
    virtual std::string toString() const = 0;
    TokenType type() = 0;
};