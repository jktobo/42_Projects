/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:39:03 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/17 18:23:15 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        FragTrap &operator = (const FragTrap &other);
        ~FragTrap();
        void highFivesGuys(void);
};
#endif