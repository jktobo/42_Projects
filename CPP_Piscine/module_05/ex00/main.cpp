/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:18 by dkaratae          #+#    #+#             */
/*   Updated: 2023/10/27 16:57:24 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bob("Bob", 1);
		bob.incGrade();
		Bureaucrat bob1("Bob", 151);
		bob1.decGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << "Result " << bob.getName() << " and grade " << bob.getGrade() << std::endl;
}