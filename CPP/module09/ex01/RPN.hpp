#ifndef RPN_PP
# define RPN_PP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN {
    private:
        std::string str;
        std::stack<float> numbers;
        std::stack<char> operators;
    public:
        RPN();
        RPN(std::string input);
        RPN(RPN const &src);
        RPN &operator=(RPN const &rhs);

        std::string getArg(void) const;

        void start();
        void performOperation();

        ~RPN();
};

#endif