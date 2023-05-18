/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:22 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/18 10:01:16 by joldosh          ###   ########.fr       */
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