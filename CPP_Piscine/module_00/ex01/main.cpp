/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:42:07 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/30 16:32:39 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"
#include "Contact.Class.hpp"

int main(void)
{
	PhoneBook book;
	std::string input;

	// while (std::cin.good())
	while (1)
	{
		book.showCommand();
		std::cout << "Enter command: ";
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "TRY TO ENTER CORRECT COMMAND!" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			break;
		}
		std::cout << std::endl;
		if (input == "ADD")
		{
			book.addContact();
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (input == "SEARCH")
		{
			book.printContacts();
			book.searchCommand();
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "UNCORRECT COMMAND!\n" << std::endl;
	}
	return (0);
}