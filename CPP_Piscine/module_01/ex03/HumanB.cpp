/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:52 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/05 19:22:58 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string a_name)
{
    name = a_name;
    flag = 0;
}

HumanB::~HumanB()
{
    
}

void HumanB::attack()
{
    if (flag)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << " Error!! " << std::endl;
    
}

void HumanB::setWeapon(Weapon &a_weapon)
{
    weapon = &a_weapon;
    this->flag = 1;
}