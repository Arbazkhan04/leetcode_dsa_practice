#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return 0; // For opening parenthesis
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix = "";
    std::stack<char> operatorStack;

    for (char c : infix) {
        if (isalnum(c)) {
            // Operand
            postfix += c;
        } else if (c == '(') {
            // Opening parenthesis
            operatorStack.push(c);
        } else if (c == ')') {
            // Closing parenthesis
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop and discard the '('
        } else if (isOperator(c)) {
            // Operator
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression = "(3 + 4) * 5";
    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;

    return 0;
}
