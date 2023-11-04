/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:45:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/04 10:52:43 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>

AForm::AForm(void) : _name("Default"), _sign(false), _gradeSign(150), _gradeExec(150) {
}

AForm::AForm(std::string const name, int const gradeSign, int const gradeExec) : _name(name), _sign(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (_gradeSign < 1 || _gradeExec < 1)
        throw AForm::GradeTooHighExeption();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw AForm::GradeTooLowExeption();
}

AForm::AForm(AForm const &copy) : _name(copy._name), _sign(copy._sign), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec) {
	
}

AForm &AForm::operator=(AForm const &other) {
	if (this != &other) {
		const_cast<std::string&>(this->_name) = other._name;
		const_cast<bool&>(this->_sign) = other._sign;
		const_cast<int&>(this->_gradeSign) = other._gradeSign;
		const_cast<int&>(this->_gradeExec) = other._gradeExec;
	}
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSign() const {
	return _sign;
}

void AForm::beSigned(Bureaucrat &bur) {
    if (bur.getGrade() <= this->getGradeSign())
    {
        if (_sign == true)
            std::cout << "The AForm sighned!" << std::endl;
        _sign = true;
    }
    else
        throw AForm::GradeTooLowExeption();
}

int AForm::getGradeSign() const{
	return _gradeSign;
}

int AForm::getGradeExec() const{
	return _gradeExec;
}


const char* AForm::GradeTooHighExeption::what() const throw() {
    return "AForm Grade is high!";
}

const char* AForm::GradeTooLowExeption::what() const throw() {
    return "AForm Grade is low!";
}
const char* AForm::TheFormIsNotSigned::what() const throw() {
    return "The Form isn't signed!";
}

std::ostream& operator<<(std::ostream &os, const AForm& print) {
    os << "Form name - " << print.getName() << std::endl 
        << print.getName() << " Grade to sign " << print.getGradeSign() << std::endl
        << print.getName() << " Grade to execute " << print.getGradeExec() << std::endl
        << "Bureaucrat is signed? - " << print.getSign() << std::endl;
    return os;
}