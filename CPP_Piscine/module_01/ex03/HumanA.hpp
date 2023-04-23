/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:50 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/23 15:51:05 by dkaratae         ###   ########.fr       */
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
        HumanA(std::string a_name, Weapon &a_weapon);
        void attack();
};

#endif