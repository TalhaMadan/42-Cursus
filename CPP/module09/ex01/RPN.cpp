#include "RPN.hpp"
#include <exception>
#include <cctype>

RPN::RPN() {}

RPN::RPN(std::string input) : str(input) {}

RPN::RPN(RPN const &src) {
    *this = src;
}

RPN &RPN::operator=(RPN const &rhs) {
    this->str = rhs.getArg();
    return (*this);
}

RPN::~RPN(void) {}

std::string RPN::getArg(void) const {
    return str;
}

void RPN::performOperation() {
    float value2 = numbers.top();
    numbers.pop();
    float value1 = numbers.top();
    numbers.pop();

    char op = operators.top();
    operators.pop();
    float result;
    switch (op) {
        case '*': 
            result = value1 * value2;
            break;
        case '+':
            result = value1 + value2;
            break;
        case '-':
            result = value1 - value2;
            break;
        case '/':
            if (value2 == 0)
                throw std::runtime_error("Error: divide by zero exception");
            result = value1 / value2;
            break;
        default:
            std::cout << "Error" << std::endl;
    }
    numbers.push(result);
}

void RPN::start(void) {
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            numbers.push(str[i] - '0');
        else if (str[i] == '+' || str[i] == '-' ||str[i] == '*' || str[i] == '/')
            operators.push(str[i]);
        else if (str[i] != ' ') {
            std::cout << "Error" << std::endl;
            return;
        }
        if (operators.size() == 1 && numbers.size() >= 2)
            performOperation();
        else if (operators.size() == 1) {
            std::cout << "Error" << std::endl;
            return;
        }
    }
    if (numbers.size()== 1 && operators.empty())
        std::cout << numbers.top() << std::endl;
    else
        std::cout << "Error" << std::endl;
}