/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:57:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/24 13:57:27 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie *zombie = new Zombie[n];
	
	for (int i = 0; i <= n; i++)
	{
		zombie[i].setName(name);
		zombie[i].announce();
	}
	return (zombie);
}