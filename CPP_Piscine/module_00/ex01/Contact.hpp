/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:06:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/13 14:21:30 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
	private:
		std::string first_name; 
		std::string last_name; 
		std::string nickname; 
		std::string phone_number; 
		std::string darkest_secret;
	public:
		setFirstName(string firstName)
		{
			this->first_name = first_name;
		}
};