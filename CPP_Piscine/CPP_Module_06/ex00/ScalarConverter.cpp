/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:49:57 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/13 14:55:50 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {

}

void ScalarConverter::convert(const std::string &str) {

    if (str.length() == 1 && !std::isdigit(str[0])) {
        char c = str[0];
        if (std::isprint(c))
            std::cout << "char :\t'" << c << "'" << std::endl;
        else
            std::cout << "char:\tundisplayable" << std::endl;
        int i = static_cast<int>(c);
        std::cout << "int:\t" << i << std::endl;
        float f = static_cast<float>(c);
        std::cout << "float:\t" << f << std::endl;
        double d = static_cast<double>(c);
        std::cout << "double:\t" << d << std::endl;
    } else {
        std::cout << "char:\t";
        try
        {
            char c = std::stoi(str);
            int i = std::stoi(str);
            if (i < -128 || i > 127)
                throw std::exception();
            if (std::isprint(c))
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "undisplayable" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "impossible" << std::endl;
        }
            
        std::cout << "int:\t";
        try
        {
            int i = std::stoi(str);
            std::cout << i << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "impossible" << std::endl;
        }
        
        size_t dec_dot = str.find('.');
        std::cout << "float:\t";
        try
        {
            float f = std::stof(str);
            if (dec_dot != std::string::npos) {
                int precision = str.length() - dec_dot - 1;
                // int f_precision = (std::numeric_limits<float>::max_digits10 < precision ? std::numeric_limits<float>::max_digits10 : precision);
                std::cout << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
                // std::cout << std::setprecision(std::numeric_limits<float>::max_digits10) << f << "f" << std::endl;
            } else {
                std::cout << f << ".0f" << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cout << "impossible" << std::endl;
        }
        
        std::cout << "double:\t";
        try
        {
            double d = std::stod(str);
            if (dec_dot != std::string::npos) {
                int precision = str.length() - dec_dot - 1;
                std::cout << std::fixed << std::setprecision(precision) << d << std::endl;
            } else {
                std::cout << d << ".0" << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cout << "impossible" << std::endl;
        }
    }
}
