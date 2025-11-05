#include <iostream>
#include "operands.h"
#include "operations.h"
#include "token.h"
#include "RPNconverter.h"
#include "RPNcalculator.h"
#include "lexEvaluation.h"


void main() {

    while (true) {
        std::string expression = "5 + 6 / 4 - 1 ";

        try {

            Lexer lexer(expression);
            std::queue<Token> tokens = lexer.tokenize();
            printTokens(tokens);

            std::cout << "----" << std::endl;
            std::queue<Token> infixCopy = copyQueue(tokens);
            std::queue<Token> rpnTokens = infixToRPN(infixCopy);
            printTokens(rpnTokens);

            std::queue<Token> rpnCopy = copyQueue(rpnTokens);
            double res = evaluateRPN(rpnCopy);
            std::cout << " ----- " << std::endl;
            std::cout << res << std::endl;

        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }

    }

    return 0;
}