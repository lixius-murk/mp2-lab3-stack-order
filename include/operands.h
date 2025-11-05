#include <iostream>
#include "token.h"

template<Class T>
class Operands: public Token {
	T value;
public: 
    Operand(T val) : value(val) {}
    T getValue() const { return value; }
    std::string toString() const override {
        return std::to_string(value);
    }
    TokenType type() {
        return TokenType::OPERAND;
    }
};