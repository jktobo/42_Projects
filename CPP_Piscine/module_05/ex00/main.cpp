/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:18 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 12:04:28 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat buroc1("Burcat1", 2);
	try {
		std::cout << buroc1 << std::endl;
		buroc1.incGrade();
		std::cout << buroc1 << std::endl;
		buroc1.incGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Bureaucrat buroc2("Burcat1", 149);
	try {
		std::cout << buroc2 << std::endl;
		buroc2.decGrade();
		std::cout << buroc2 << std::endl;
		buroc2.decGrade();
		std::cout << buroc2 << std::endl;
		buroc2.decGrade();
		std::cout << buroc2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << "Result " << bob.getName() << " and grade " << bob.getGrade() << std::endl;
	return (0);
}