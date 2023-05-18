/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:39 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/18 10:40:11 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("Earth");

    scavTrap.attack("Mars");
    scavTrap.takeDamage(30);
    scavTrap.beRepaired(15);
    scavTrap.guardGate();

    return (0);
}