/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:42:07 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/19 15:40:38 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
// #include <string>
// #include <iostream>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	PhoneBook book;
	std::string input;

	while (1)
	{
		book.showCommand();
		std::cout << "Enter command: ";
		std::cin >> input; 
		std::cout << std::endl;
		if (input == "ADD")
			book.addContact();
		else if (input == "SEARCH")
		{
			book.printContacts();
			
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "It isn't correct command!" << std::endl;
	}
	return (0);
}