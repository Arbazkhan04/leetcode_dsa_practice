#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return 0; // For opening parenthesis
}

std::string infixToPrefix(const std::string& infix) {
    std::string prefix = "";
    std::stack<char> operatorStack;

    // Reverse the infix expression
    std::string reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    for (char c : reversedInfix) {
        if (isalnum(c)) {
            // Operand
            prefix += c;
        } else if (c == ')') {
            // Closing parenthesis
            operatorStack.push(c);
        } else if (c == '(') {
            // Opening parenthesis
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop and discard the ')'
        } else if (isOperator(c)) {
            // Operator
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                prefix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        prefix += operatorStack.top();
        operatorStack.pop();
    }

    // Reverse the prefix expression to get the final result
    std::reverse(prefix.begin(), prefix.end());
    
    return prefix;
}

int main() {
    std::string infixExpression = "4*5/6-(9+4)";
    std::string prefixExpression = infixToPrefix(infixExpression);
    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Prefix Expression: " << prefixExpression << std::endl;

    return 0;
}
