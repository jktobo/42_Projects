/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:46 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/17 12:16:41 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "Default constructor ScavTrap called" << std::endl;
    _name = "ScavTrap_default";
    _hitPoints = 100;
    _energyPoints = 50;
    _atackDamage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor ScavTrap with parameter called" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _atackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor ScavTrap called" << std::endl;
}

// ClapTrap& ClapTrap::operator = (const ClapTrap &other)
// {
//     std::cout << "Copy assignment operator ClapTrap called" << std::endl;
//     if (this != &other)
//     {
//         _name = other._name;
//         _hitPoints = other._hitPoints;
//         _energyPoints = other._energyPoints;
//         _atackDamage = other._atackDamage;
//     }
//     return *this;
// }

// ClapTrap::~ClapTrap()
// {
//     std::cout << "Destructor ClapTrap called" << std::endl;
// }

// void ClapTrap::attack(const std::string &target)
// {
//     if (_hitPoints <= 0)
//     {
//         std::cout << "ClapTrap " << _name << " can't attack, it hasn't hitpoint" << std::endl;
//         return;
//     }
//     else if (_energyPoints <= 0)
//     {
//         std::cout << "ClapTrap " << _name << " can't attack, it hasn't energypoint" << std::endl;
//         return;
//     }
//     std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _atackDamage << " points of damage!" << std::endl;
//     // _hitPoints = _hitPoints - _atackDamage;
//     _energyPoints--;
// }