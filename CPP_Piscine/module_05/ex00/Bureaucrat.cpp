/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/10/23 16:42:49 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(0) {
	std::cout << "Called defalult constructor with name " << getName() << " and grade " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default") { 
	
	try
	{
		setGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Constructions " << getName() << " failed" << e.what() << " Grade not set to 1" << getGrade() << std::endl;
		setGrade(1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Constructions " << getName() << " failed" << e.what() << " Grade not set to 150" << getGrade() << std::endl; 
		setGrade(150);
	}
}

Bureaucrat::Bureaucrat(std::string name) : _name(name) {
	std::cout << "Called constructor with name " << _name << std::endl;
}
