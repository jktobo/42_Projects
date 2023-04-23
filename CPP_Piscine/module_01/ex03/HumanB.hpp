/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:54 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/23 14:07:10 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANB_HPP
#define HUMANB_HPP

class HumanB
{
    private:
        std::string name;
        Weapon &weapon;
    public:
        ~HumanB();
        HumanB(std::string const &a_name);
        void attack();
        void setWeapon(Weapon &a_weapon);
};

#endif