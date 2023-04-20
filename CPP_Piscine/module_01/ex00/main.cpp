/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:53:47 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/20 16:53:52 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie foo;
    foo.announce();

    Zombie *first = newZombie("Heap");
    first->announce();
    delete(first);

    randomChump("Stack");

    return (0);
}