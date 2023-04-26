/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:42:07 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/25 13:18:00 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"
#include "Contact.Class.hpp"

int main(void)
{
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
			book.searchCommand();
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "UNCORRECT COMMAND!\n" << std::endl;
	}
	return (0);
}