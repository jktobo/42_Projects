/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:06:46 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/19 19:51:12 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	countContact = 0;
}
PhoneBook::~PhoneBook()
{
	
}

void PhoneBook::addContact(void)
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;
	if (countContact < 8)
	{
		std::cout << "Enter first name: ";
		std::cin >> first_name;
		array[countContact].setFirstName(first_name);

		std::cout << "Enter last name: ";
		std::cin >> last_name;
		array[countContact].setLastName(last_name);
		
		std::cout << "Enter nickname: ";
		std::cin >> nickname;
		array[countContact].setNickName(nickname);
		
		std::cout << "Enter phone number: ";
		std::cin >> phone_number;
		array[countContact].setPhoneNunber(phone_number);
		
		std::cout << "Enter darkest secret: ";
		std::cin >> darkest_secret;
		array[countContact].setDarkestSecret(darkest_secret);
		countContact++;
	}	
	else
		countContact = 0;
}

void PhoneBook::printContacts(void)
{
	std::cout << "|---------- ---------- ---------- ----------|" << std::endl;
	std::cout << "|   index  |first name| last name| nickname |" << std::endl;
	std::cout << "|---------- ---------- ---------- ----------|" << std::endl;
 
 	for (int i = 0; i < 8; i++)
	{
		if (array[i].getFirstName().empty())
			break;
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(11) << (array[i].getFirstName().length() > 10 ? array[i].getFirstName().substr(0, 9) + ".|" : array[i].getFirstName() + "|");
		std::cout << std::setw(11) << (array[i].getLastName().length() > 10 ? array[i].getLastName().substr(0, 9) + ".|" : array[i].getLastName() + "|");
		std::cout << std::setw(11) << (array[i].getNickName().length() > 10 ? array[i].getNickName().substr(0, 9) + ".|" : array[i].getNickName() + "|");
		std::cout << std::endl;
		std::cout << "|----------+----------+----------+----------|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void PhoneBook::searchCommand(void)
{
	int i;
	int input;
	
	i = 0;
	if (array[i].getFirstName().empty())
	{
		std::cout << "CONTACT IS EMPTY!\n" << std::endl;
		return ;
	}
	for (i = 0; i < 8; i++)
		if (array[i].getFirstName().empty())
			break;
	std::cout << "Enter index: ";
	std::cin >> input;
	if (input > 0 && input <= i)
	{
		std::cout << std::setw(16) << "FIRST NAME: " << array[input -1].getFirstName() << std::endl;
		std::cout << std::setw(16) << "LAST NAME: " << array[input -1].getLastName() << std::endl;
		std::cout << std::setw(16) << "NICKNAME: " << array[input -1].getNickName() << std::endl;
		std::cout << std::setw(16) << "PHONE NUMBER: " << array[input -1].getPhoneNunber() << std::endl;
		std::cout << std::setw(16) << "DARKEST SECRET: " << array[input -1].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "UNCORRECT INDEX!" << std::endl;
	std::cout << std::endl;
	std::cin.clear();
	// std::cin.ignore(32767, '\n');
}

void PhoneBook::showCommand(void)
{
	std::cout << "**************************************" << std::endl;
	std::cout << "************** PHONEBOOK *************" << std::endl;
	std::cout << "**************************************" << std::endl;
	std::cout << "|------------------------------------|" << std::endl;
	std::cout << "|         Available command:         |" << std::endl;
	std::cout << "|------------------------------------|" << std::endl;
	std::cout << "|    ADD                             |" << std::endl;
	std::cout << "|    SEARCH                          |" << std::endl;
	std::cout << "|    EXIT                            |" << std::endl;
	std::cout << "|____________________________________|" << std::endl;
	std::cout << std::endl;
}