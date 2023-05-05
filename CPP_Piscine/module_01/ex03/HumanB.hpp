/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:54 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/05 19:21:44 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANB_HPP
#define HUMANB_HPP

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
        int flag;
    public:
        ~HumanB();
        HumanB(std::string a_name);
        void attack();
        void setWeapon(Weapon &a_weapon);
};

#endif