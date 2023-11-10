/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:18 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 09:53:42 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat buroc1("Burcat1", 2);
		buroc1.incGrade();
		Bureaucrat buroc2("Burcat2", 149);
		buroc2.decGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << "Result " << bob.getName() << " and grade " << bob.getGrade() << std::endl;
	return (0);
}