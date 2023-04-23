/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:52 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/23 14:10:15 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const &a_name)
{
    name = a_name;
}

HumanB::~HumanB()
{
    
}

void HumanB::attack()
{
    if (weapon != nullptr)
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon &a_weapon)
{
    weapon = &a_weapon;
}