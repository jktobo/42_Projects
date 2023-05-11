/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:27 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/11 16:49:31 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "Default constructor called" << std::endl;
    _name = "default";
    _hitPoints = 10;
    _energyPoints = 10;
    _atackDamage = 0;
}
ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Constructor with parameter called" << std::endl;
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _atackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _atackDamage << " points of damage!" << std::endl;
    _hitPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " was damage " << amount << ", and has  " << _hitPoints << " points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " was repaired " << amount << ", and has  " << _hitPoints << " points!" << std::endl;
}
