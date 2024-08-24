#include <iostream>
#include <string>

bool isBalanced(const std::string& expression) {
    Stack stack;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.Push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.IsEmpty()) {
                return false;
            }

            char top = stack.Top();
            stack.Pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If stack is not empty, then parentheses are unbalanced
    return stack.IsEmpty();
}

int main() {
    std::string expression;

    std::cout << "Enter an expression: ";
    std::cin >> expression;

    if (isBalanced(expression)) {
        std::cout << "The expression is balanced." << std::endl;
    } else {
        std::cout << "The expression is not balanced." << std::endl;
    }

    return 0;
}

