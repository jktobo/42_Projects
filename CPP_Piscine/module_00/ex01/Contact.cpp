/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:06:39 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/19 14:35:57 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact ()
{
	
}

Contact::~Contact ()
{
	
}

// void Contact::newContact()
// {
// 	std::cout << "Enter first name: ";
// 	std::cin >> p_first_name;

// 	std::cout << "Enter last name: ";
// 	std::cin >> p_last_name;

// 	std::cout << "Enter nickname: ";
// 	std::cin >> p_nickname;

// 	std::cout << "Enter phone number: ";
// 	std::cin >> p_phone_number;

// 	std::cout << "Enter darkest secret: ";
// 	std::cin >> p_darkest_secret;
// }

// Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
// {
// 	p_first_name = first_name;
// 	p_last_name = last_name;
// 	p_nickname = nickname;
// 	p_phone_number = phone_number;
// 	p_darkest_secret = darkest_secret;
// }

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