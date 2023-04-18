/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:06:39 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/18 14:45:01 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact ()
{
	
}

Contact::~Contact ()
{
	
}

void Contact::newContact()
{
	std::cout << "Enter first name: ";
	std::cin >> first_name;

	std::cout << "Enter last name: ";
	std::cin >> last_name;

	std::cout << "Enter nickname: ";
	std::cin >> nickname;

	std::cout << "Enter phone number: ";
	std::cin >> phone_number;

	std::cout << "Enter darkest secret: ";
	std::cin >> darkest_secret;
}

// Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
// {
// 	first_name_ = first_name;
// 	last_name_ = last_name;
// 	nickname_ = nickname;
// 	phone_number_ = phone_number;
// 	darkest_secret_ = darkest_secret;
// }