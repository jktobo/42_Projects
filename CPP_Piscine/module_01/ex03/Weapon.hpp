/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:45 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/23 13:17:25 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string a_type);
		~Weapon();
		const std::string &getType();
		void setType(std::string const &a_type);
};
#endif