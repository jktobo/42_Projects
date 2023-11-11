#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &copy);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string &str);
};

#endif