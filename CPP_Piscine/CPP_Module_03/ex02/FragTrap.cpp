/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:35:43 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/31 18:35:45 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "Default constructor FragTrap called" << std::endl;
    _name = "FragTrap_default";
    _hitPoints = 100;
    _energyPoints = 100;
    _atackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor FragTrap with parameter called" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _atackDamage = 20;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "Copy constructor FragTrap called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &other)
{
    std::cout << "Copy assignment operator FragTrap called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " high fives!" << std::endl;
}