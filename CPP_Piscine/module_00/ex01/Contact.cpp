/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:06:39 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/15 17:15:28 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>

class Contact
{
	private:
		std::string first_name_; 
		std::string last_name_; 
		std::string nickname_; 
		std::string phone_number_; 
		std::string darkest_secret_;
	public:
	Contact ()
	{
		
	}
	
	~Contact ()
	{
		
	}
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
	{
		first_name_ = first_name;
		last_name_ = last_name;
		nickname_ = nickname;
		phone_number_ = phone_number;
		darkest_secret_ = darkest_secret;
	}
};