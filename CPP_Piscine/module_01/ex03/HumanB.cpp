/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:52 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/08 18:56:21 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string a_name)
{
    name = a_name;
    weapon = NULL;
}

HumanB::~HumanB()
{
    
}

void HumanB::attack()
{
    if (!weapon)
        std::cout << " Error!! " << std::endl;
    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &a_weapon)
{
    weapon = &a_weapon;
}