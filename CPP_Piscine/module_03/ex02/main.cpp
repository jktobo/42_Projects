/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:39:06 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/18 10:39:38 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clapTrap("Earth");
    clapTrap.attack("Mars");
    clapTrap.takeDamage(20);
    clapTrap.beRepaired(10);

    ScavTrap scavTrap("Earth");
    scavTrap.attack("Mars");
    scavTrap.takeDamage(30);
    scavTrap.beRepaired(15);
    scavTrap.guardGate();

    FragTrap fragTrap("Earth");
    fragTrap.attack("Mars");
    fragTrap.takeDamage(40);
    fragTrap.beRepaired(20);
    fragTrap.highFivesGuys();
    return (0);
}