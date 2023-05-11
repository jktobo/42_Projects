/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:27 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/10 20:44:57 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    atackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    
}

// void ClapTrap::attack(const std::string &target)
// {
    
// }

// void ClapTrap::takeDamage(unsigned int amount)
// {
    
// }

// void ClapTrap::beRepaired(unsigned int amount)
// {
    
// }

int ClapTrap::getH(void)
{
    return hitPoints;
}

int ClapTrap::getP(void)
{
    return energyPoints;
}

int ClapTrap::getD(void)
{
    return atackDamage;
}