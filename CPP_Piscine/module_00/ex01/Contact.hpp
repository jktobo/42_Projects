/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:06:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/18 15:54:47 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef		CONTACT_HPP
#define		CONTACT_HPP

#include <string>
#include <iostream>

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
	void newContact();
	
	// Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
};
#endif