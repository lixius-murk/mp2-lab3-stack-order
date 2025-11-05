#include <iostream>
#include "token.h"
#include "operations.h"
#include "operands.h"





double RPNcalculator(std::queue<Token>& tokens) {
    std::stack<double> values;

    while (!tokens.empty()) {
        Token token = tokens.front();
        tokens.pop();

        if (token.type == TokenType::NUMBER) {
            values.push(token.value);
        }
        else if (token.isOperation()) {
            if (values.size() < 2) {
                throw std::runtime_error("Недостаточно операндов!");
            }

            double right = values.top(); values.pop();
            double left = values.top(); values.pop();
            double result;

            switch (token.type) {
            case TokenType::ADD:
                result = left + right;
                break;
            case TokenType::SUBTRACT:
                result = left - right;
                break;
            case TokenType::MULTIPLY:
                result = left * right;
                break;
            case TokenType::DIVIDE:
                if (right == 0) {
                    throw std::runtime_error("Деление на 0!");
                }
                result = left / right;
                break;
            default:
                throw std::runtime_error("Неизвестная операция!");
            }

            values.push(result);
        }
    }

    if (values.size() != 1) {
        throw std::runtime_error("Ошибка конверизации!");
    }

    return values.top();
}