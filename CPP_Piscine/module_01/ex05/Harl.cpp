/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:27 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/29 20:17:18 by dkaratae         ###   ########.fr       */
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

// void Harl::ShowInfo(std::string(Harl::*ptr)())
void Harl::ShowInfo(void(Harl::*ptr)())
{
    (this->*ptr)();
}

void Harl::complain(std::string level)
{
    std::cout << level << std::endl;
    void (Harl::*p)() = nullptr;
    p = &Harl::debug;
    (this->*p)();
    // ShowInfo(error);
    
    // void (Harl::*ptr)(void) = nullptr;

    
    // ptr = &Harl::debug;
    
    // (this->*ptr)();
}