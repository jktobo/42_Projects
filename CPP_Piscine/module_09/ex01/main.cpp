#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "You should enter numbers and operator!" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn(argv[1]);
        std::cout << rpn.calculate() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR! " << e.what() << '\n';
    }
    return(0);
}