/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:27 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/02 14:57:06 by dkaratae         ###   ########.fr       */
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
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

std::string Harl::test(void)
{
    return "This is unacceptable! I want to speak to the manager now.";
}

void Harl::complain(std::string level)
{
    char c = level[0];
    void (Harl::*p)() = nullptr;
    switch (c) {
        case 'd':
            p = &Harl::debug;
            break;
        case 'i':
            p = &Harl::info;
            break;
        case 'w':
            p = &Harl::warning;
            break;
        case 'e':
            p = &Harl::error;
            break;
        default:
            std::cout << "Error!" << std::endl;
            break;
    }
    (this->*p)();
}