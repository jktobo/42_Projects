/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:06:39 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/19 19:43:45 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact ()
{
	
}

Contact::~Contact ()
{
	
}

void Contact::setFirstName(std::string first_name)
{
	p_first_name = first_name;
}
void Contact::setLastName(std::string last_name)
{
	p_last_name = last_name;
}
void Contact::setNickName(std::string nickname)
{
	p_nickname = nickname;
}
void Contact::setPhoneNunber(std::string phone_number)
{
	p_phone_number = phone_number;
}
void Contact::setDarkestSecret(std::string darkest_secret)
{
	p_darkest_secret = darkest_secret;
}

std::string Contact::getFirstName(void)
{
	return p_first_name;
}
std::string Contact::getLastName(void)
{
	return p_last_name;
}
std::string Contact::getNickName(void)
{
	return p_nickname;
}
std::string Contact::getPhoneNunber(void)
{
	return p_phone_number;
}
std::string Contact::getDarkestSecret(void)
{
	return p_darkest_secret;
}