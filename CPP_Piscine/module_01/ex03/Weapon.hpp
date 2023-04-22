/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:45 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/22 16:52:13 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon::Weapon()
		{
			
		}
		
		Weapon::~Weapon()
		{
			
		}
		
		const std::string &getType()
		{
			return (type);
		}
		
		void setType(std::string a_type)
		{
			type = a_type;
		}
		
}