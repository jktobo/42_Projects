/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/10/24 16:18:22 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(0) {
	std::cout << "Called defalult constructor with name " << getName() << " and grade " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default") { 
	
	try
	{
		_grade = grade;
		if (grade < 0)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Constructions " << getName() << " failed" << e.what() << " Grade not set to 1" << getGrade() << std::endl;
		_grade = 1;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Constructions " << getName() << " failed" << e.what() << " Grade not set to 150" << getGrade() << std::endl; 
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat(std::string name) : _name(name) {
	std::cout << "Called constructor with parametr name " << _name << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Called constructor with parametr name " << _name  << " and grade" << _grade << std::endl;
}

// void Bureaucrat::setName(std::string name) {
// 	_name = name;
// }

// void Bureaucrat::setGrade(int grade) {
// 	_grade = grade;
// }

std::string Bureaucrat::getName()
{
	return _name;
}

int Bureaucrat::getGrade()
{
	return _grade;
}

void Bureaucrat::incGrade()
{
	_grade--;
}

void Bureaucrat::decGrade()
{
	_grade++;
}

Bureaucrat:: ~Bureaucrat()
{
	
}