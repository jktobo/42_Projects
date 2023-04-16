/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:06:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/16 14:49:38 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef		CONTACT_HPP
#define		CONTACT_HPP
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
	Contact ();
	~Contact ();
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
};
#endif