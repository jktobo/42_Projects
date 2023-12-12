/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:57:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/02 16:26:14 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie *zombie = new Zombie[n];
	
	for (int i = 0; i < n; i++)
	{
		zombie[i].setName(name);
		zombie[i].announce();
	}
	return (zombie);
}