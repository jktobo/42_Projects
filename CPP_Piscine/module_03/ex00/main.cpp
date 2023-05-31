/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:22 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/19 22:22:47 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapT("Earth");
    
    clapT.attack("Mars");
    clapT.takeDamage(4);
    clapT.beRepaired(3);

    
    return (0);
}