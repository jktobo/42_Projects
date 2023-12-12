/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:57:57 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/22 16:17:17 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::endl;
	
	std::cout << "The memory address of the string variable.\t" << &str << std::endl;
	std::cout << "The memory address held by stringPTR.\t\t" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF.\t\t" << &stringREF << std::endl;
	
	std::cout << std::endl;

	std::cout << "The value of the string variable.\t" << str << std::endl;
	std::cout << "The value pointed to by stringPTR.\t" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF.\t" << stringREF << std::endl;
	
	std::cout << std::endl;
	return (0);
}