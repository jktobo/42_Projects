/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:06:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/27 16:25:59 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef		CONTACT_HPP
#define		CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string p_first_name; 
		std::string p_last_name; 
		std::string p_nickname; 
		std::string p_phone_number; 
		std::string p_darkest_secret;
	public:
	Contact ();
	~Contact ();
	void setFirstName(std::string);
	void setLastName(std::string);
	void setNickName(std::string);
	void setPhoneNunber(std::string);
	void setDarkestSecret(std::string);
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickName(void);
	std::string getPhoneNunber(void);
	std::string getDarkestSecret(void);
};
#endif