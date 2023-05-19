/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:46 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/17 14:35:09 by dkaratae         ###   ########.fr       */
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

// ScavTrap& ScavTrap::operator = (const ScavTrap &other)
// {
//     std::cout << "Copy assignment operator ScavTrap called" << std::endl;
//     if (this != &other)
//     {
//         _name = other._name;
//         _hitPoints = other._hitPoints;
//         _energyPoints = other._energyPoints;
//         _atackDamage = other._atackDamage;
//     }
//     return *this;
// }

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap called" << std::endl;
}

// void ScavTrap::attack(const std::string &target)
// {

// }