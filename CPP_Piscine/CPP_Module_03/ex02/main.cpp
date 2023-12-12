/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:39:06 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/31 17:35:53 by dkaratae         ###   ########.fr       */
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