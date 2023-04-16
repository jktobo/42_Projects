/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:42:07 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/16 17:46:51 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	PhoneBook book;
	std::string input;

	while (1)
	{
		std::cout << "Enter command: ";
		std::cin >> input; 
		if (input == "ADD")
			
		else if (input == "SEARCH")
			
		else if (input == "EXIT")
			break;
		else
			std::cout << "It isn't correct command!"
	}
	return (0);
}