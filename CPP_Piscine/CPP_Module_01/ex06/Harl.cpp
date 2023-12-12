/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:10 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/11 20:10:42 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    
}

Harl::~Harl()
{
    
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
    std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;
    for (i = 0; i < 4; i++)
        if (level == array[i])
            break;
    void (Harl::*p)() = NULL;
    switch (i) {
        case 0:
            p = &Harl::debug;
            break;
        case 1:
            p = &Harl::info;
            break;
        case 2:
            p = &Harl::warning;
            break;
        case 3:
            p = &Harl::error;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            return;
    }
    (this->*p)();
}

// void Harl::complain(std::string level)
// {
//     char c = level[0];
    
//     void (Harl::*p)() = NULL;
    
//     switch (c) {
//         case 'd':
//             p = &Harl::debug;
//             break;
//         case 'D':
//             p = &Harl::debug;
//             break;
//         case 'i':
//             p = &Harl::info;
//             break;
//         case 'I':
//             p = &Harl::info;
//             break;
//         case 'w':
//             p = &Harl::warning;
//             break;
//         case 'W':
//             p = &Harl::warning;
//             break;
//         case 'e':
//             p = &Harl::error;
//             break;
//         case 'E':
//             p = &Harl::error;
//             break;
//         default:
//             std::cout << "Error!" << std::endl;
//             break;
//     }
//     (this->*p)();
// }