#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

bool isOperator(const std::string& token)
{
    static const std::unordered_map<std::string, int> operators = {
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2},
        {"%", 2},
        {"^", 3}
    };
    return operators.count(token) > 0;
}

bool isOperand(const std::string& token)
{
    return !isOperator(token) && token != "(" && token != ")";
}

int precedence(const std::string& op)
{
    static const std::unordered_map<std::string, int> operators = {
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2},
        {"%", 2},
        {"^", 3}
    };
    return operators.at(op);
}

std::vector<std::string> infixToPostfix(const std::vector<std::string>& infix)
{
    std::stack<std::string> s;
    std::vector<std::string> postfix;

    for (const auto& token : infix) {
        if (isOperand(token)) {
            postfix.push_back(token);
        } else if (token == "(") {
            s.push(token);
        } else if (token == ")") {
            while (!s.empty() && s.top() != "(") {
                postfix.push_back(s.top());
                s.pop();
            }
            if (s.empty()) {
                throw std::runtime_error("Unmatched parenthesis");
            }
            s.pop();
        } else if (isOperator(token)) {
            while (!s.empty() && s.top() != "(" && precedence(token) <= precedence(s.top())) {
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(token);
        }
    }

    while (!s.empty()) {
        if (s.top() == "(") {
            throw std::runtime_error("Unmatched parenthesis");
        }
        postfix.push_back(s.top());
        s.pop();
    }

    return postfix;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    const auto postfix = infixToPostfix(tokens);

    for (const auto& token : postfix) {
        std::cout << token << " ";
    }
    std::cout << std::endl;

    return 0;
}

/* 
3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3
3 4 2 * 1 5 - 2 ^ 3 ^ / +
 */