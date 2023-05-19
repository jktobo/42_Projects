/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:39 by dkaratae          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/17 16:16:54 by dkaratae         ###   ########.fr       */
=======
/*   Updated: 2023/05/18 10:40:11 by joldosh          ###   ########.fr       */
>>>>>>> 19cbf8083f5ddbe562201ad9a944f44ce8ecaa9d
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
<<<<<<< HEAD
    ScavTrap bob("My");
    // bob.attack("B");
    // bob.takeDamage(4);
    // bob.beRepaired(3);


    ScavTrap jon(bob);
=======
    ScavTrap scavTrap("Earth");
>>>>>>> 19cbf8083f5ddbe562201ad9a944f44ce8ecaa9d

    scavTrap.attack("Mars");
    scavTrap.takeDamage(30);
    scavTrap.beRepaired(15);
    scavTrap.guardGate();

    return (0);
}