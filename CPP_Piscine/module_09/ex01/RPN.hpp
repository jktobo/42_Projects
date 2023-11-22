#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <stack>

class RPN {
    private:
        std::string const _arg;
        std::stack<int> stek;

    public:
        RPN(std::string const arg);
        int calculate();
};

#endif