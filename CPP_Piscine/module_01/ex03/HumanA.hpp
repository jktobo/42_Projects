/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:50 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/23 13:41:05 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string.h>
class HumanA
{
    private:
        std::string name;
        Weapon &weapon;
    public:
        ~HumanA();
        HumanA(std::string const &a_name, Weapon &a_weapon);
        void attack();
};

#endif