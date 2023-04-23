/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:40 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/23 13:17:40 by joldosh          ###   ########.fr       */
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

void Weapon::setType(std::string const &a_type)
{
    type = a_type;
}