#include "Span.hpp"
#include <list>

int main()
{
    Span sp = Span(1000);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(41);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error! " << e.what() << '\n';
    }
    // sp.addRandomNumbers(1000);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    // std::cout << "---------------------" << std::endl;
    // sp.printSpan();
    return (0);
}