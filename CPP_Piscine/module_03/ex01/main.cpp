/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:39 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/17 16:16:54 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap bob("My");
    // bob.attack("B");
    // bob.takeDamage(4);
    // bob.beRepaired(3);


    ScavTrap jon(bob);


    return (0);
}