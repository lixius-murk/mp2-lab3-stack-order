#include<iostream>
#include "token.h"
class Operations: public Token {
public:
	virtual int getPriority() = 0;
	virtual std::string getOperand() = 0;
};
class Bracket : public Operation{
    bool isOpen;
public:
    Bracket(bool open) : isOpen(open) {}

    int getPriority() const override {
        return isOpen ? 0 : -1;
    }

    bool isOpenBracket() const { return isOpen; }
    bool isBinary() const override { return false; }

    std::string toString() const override {
        return isOpen ? "(" : ")";
    }
    TokenType type() {
        return isOpen ? TokenType::OPEN_BRACKET | TokenType::CLOSE_BRACKET;
    }
};

class Add : public Operation {
public:
    int getPriority() const override { return 1; }
    bool isBinary() const override { return true; }
    std::string toString() const override { return "+"; }
    TokenType type() {
        return TokenType::ADD;
    }
};

class Sub : public Operation {
public:
    int getPriority() const override { return 1; }
    bool isBinary() const override { return true; }
    std::string toString() const override { return "-"; }
    TokenType type() {
        return TokenType::SUB;
    }
};

class Mult : public Operation {
public:
    int getPriority() const override { return 2; }
    bool isBinary() const override { return true; }
    std::string toString() const override { return "*"; }
    TokenType type() {
        return TokenType::MULT;
    }
};

class Div: public Operation {
public:
    int getPriority() const override { return 2; }
    bool isBinary() const override { return true; }
    std::string toString() const override { return "/"; }
    TokenType type() {
        return TokenType::DIV;
    }
};

