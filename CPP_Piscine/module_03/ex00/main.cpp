/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:22 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/10 20:46:24 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob("My");
    std::cout << bob.getH() << std::endl;
    std::cout << bob.getP() << std::endl;
    std::cout << bob.getD() << std::endl;
    return (0);
}