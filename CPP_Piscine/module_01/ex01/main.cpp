/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:56:09 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/28 15:30:47 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int n;

	n = 1; //check for negative
	Zombie *zombie;
	zombie = zombieHorde(n, "horde");

	delete [] zombie;
	return (0);
}