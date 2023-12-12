/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:54 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/08 18:52:39 by dkaratae         ###   ########.fr       */
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
    public:
        ~HumanB();
        HumanB(std::string a_name);
        void attack();
        void setWeapon(Weapon &a_weapon);
};

#endif