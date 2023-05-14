/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:27 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/14 13:54:24 by joldosh          ###   ########.fr       */
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

ClapTrap::ClapTrap(const ClapTrap &other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _atackDamage = other._atackDamage;
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _atackDamage = other._atackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack, it hasn't hitpoint" << std::endl;
        return;
    }
    else if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack, it hasn't energypoint" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _atackDamage << " points of damage!" << std::endl;
    // _hitPoints = _hitPoints - _atackDamage;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " was damage " << amount << " points, and has  " << _hitPoints << " points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " was repaired " << amount << " points, and has  " << _hitPoints << " points!" << std::endl;
}
