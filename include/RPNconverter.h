#include <iostream>
#include "token.h"
#include "operations.h"
#include "operands.h"

std::queue<Token> RPNconverter(std::queue<Token>& infixTokens) {
    std::queue<Token> outputQueue;
    std::stack<Token> operatorStack;

    while (!infixTokens.empty()) {
        Token token = infixTokens.front();
        infixTokens.pop();

       if (token.type == TokenType::NUMBER) {
            outputQueue.push(token);
        }
        else if (token.type == TokenType::OPEN_BRACKET) {
            operatorStack.push(token);
        }
        else if (token.type == TokenType::CLOSE_BRACKET) {
            while (!operatorStack.empty() &&
                operatorStack.top().type != TokenType::OPEN_BRACKET) {
                outputQueue.push(operatorStack.top());
                operatorStack.pop();
            }

            if (!operatorStack.empty() &&
                operatorStack.top().type == TokenType::OPEN_BRACKET) {
                operatorStack.pop();
            }
            else {
                throw std::runtime_error("Недостаточно скобок!");
            }
        }
        else if (token.isOperation()) {
            while (!operatorStack.empty() &&
                operatorStack.top().isOperation() &&
                token.getPriority() <= operatorStack.top().getPriority()) {
                outputQueue.push(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(token);
        }
    }

    while (!operatorStack.empty()) {
        if (operatorStack.top().type == TokenType::OPEN_BRACKET) {
            throw std::runtime_error("Недостаточно скобок!");
        }
        outputQueue.push(operatorStack.top());
        operatorStack.pop();
    }

    return outputQueue;
}