/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:56:09 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/08 16:33:45 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int n;

	n = 20;
	if (n > 0)
	{
		Zombie *zombie = zombieHorde(n, "horde1");
		delete [] zombie;
	}
	return (0);
}