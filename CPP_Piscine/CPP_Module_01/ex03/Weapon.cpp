/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:40 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/23 15:49:29 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon()
{
    
}

Weapon::Weapon(std::string a_type)
{
    type = a_type;
}

Weapon::~Weapon()
{
    
}

const std::string& Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string a_type)
{
    type = a_type;
}