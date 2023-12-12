/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 12:05:00 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

// Bureaucrat::Bureaucrat(const Bureaucrat &other) {
// 	*this = other;
// }
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		const_cast<std::string&>(this->_name) = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

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
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decGrade() {
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

Bureaucrat:: ~Bureaucrat() {
	
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &print) {
	os << print.getName() << " " << print.getGrade() << std::endl;
	return os;
}
