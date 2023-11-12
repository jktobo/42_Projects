/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:49:41 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/12 14:51:01 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// int main (int ac, char **av) {
    
//     return (0);
// }

int main(int ac, char **av)
{
    bool is_digit = false;
    bool is_alpha = false;
    int count_letter = 0;

	if (ac != 2)
	{
		std::cout << "Error: You should use like this $ ./convert [INPUT]" << std::endl;
		return (1);
	}
    for (size_t i = 0; i < strlen(av[1]); i++)
    {
        if (isalpha(av[1][i])) {
            is_alpha = true;
            count_letter++;
        }
        if (isdigit(av[1][i]))
            is_digit = true;
    }
    
    if (is_digit && is_alpha && count_letter > 0) {
        if (count_letter == 1) {
            for (size_t i = 0; i < strlen(av[1]); i++) {
                if (av[1][i] == 'f' && av[1][i] == '\0') {
                    ScalarConverter::convert(av[1]);
                }
            }
            std::cout << "It isn't correct INPUT!" << std::endl;
            return (1);  
        } else {
            std::cout << "It isn't correct INPUT!" << std::endl;
            return (1);
        }
    } else {
        ScalarConverter::convert(av[1]);
    }
	return (0);
}