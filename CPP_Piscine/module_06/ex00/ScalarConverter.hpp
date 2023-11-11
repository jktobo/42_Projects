/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:04 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/11 16:50:06 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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