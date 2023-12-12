/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:39:11 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/31 18:36:57 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "Default constructor ScavTrap called" << std::endl;
    _name = "ScavTrap_default";
    _hitPoints = 100;
    _energyPoints = 50;
    _atackDamage = 20;
}
ScavTrap::ScavTrap(std::string name)
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

ScavTrap& ScavTrap::operator = (const ScavTrap &other)
{
    std::cout << "Copy assignment operator ScavTrap called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack, it hasn't hitpoint" << std::endl;
        return;
    }
    else if (_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack, it hasn't energypoint" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _atackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}
void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
