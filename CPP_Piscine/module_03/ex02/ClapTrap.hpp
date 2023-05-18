/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:38:58 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/17 18:19:40 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _atackDamage;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator = (const ClapTrap &other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif