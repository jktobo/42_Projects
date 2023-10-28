/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/10/28 16:53:51 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
// #include <exception>
// #include <functional>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Called defalult constructor with name " << getName() << " and grade " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

// Bureaucrat::Bureaucrat &operator=(const Bureaucrat &other) {
	
// }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is low!";
}

std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incGrade() {
	try {
		if (_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		else
		 	_grade--;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decGrade() {
	try {
		if (_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		else
		 	_grade++;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat:: ~Bureaucrat() {}

std::ostream &operator << (std::ostream &os, const Bureaucrat &print) {
	os << print.getName() << " " << print.getGrade() << std::endl;
	return os;
}
