/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:43:58 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/02 13:15:43 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>

Form::Form(void) : _name("Default"), _sign(false), _gradeSign(150), _gradeExec(150) {
}

Form::Form(std::string const name, int const gradeSign, int const gradeExec) : _name(name), _sign(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (_gradeSign < 1 || _gradeExec < 1)
        throw Form::GradeTooHighExeption();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw Form::GradeTooLowExeption();
}

Form::~Form() {}

std::string Form::getName() const {
	return _name;
}

bool Form::getSign() const {
	return _sign;
}

void Form::beSigned(Bureaucrat &bur) {
    if (bur.getGrade() <= this->getGradeSign())
    {
        if (_sign == true)
            std::cout << "The Form sighned!" << std::endl;
        _sign = true;
    }
    else
        throw Form::GradeTooLowExeption();
}

int Form::getGradeSign() const{
	return _gradeSign;
}

int Form::getGradeExec() const{
	return _gradeExec;
}


const char* Form::GradeTooHighExeption::what() const throw() {
    return "Form Grade is high!";
}

const char* Form::GradeTooLowExeption::what() const throw() {
    return "Form Grade is low!";
}

std::ostream& operator<<(std::ostream &os, const Form& print) {
    os << "Form name - " << print.getName() << std::endl 
        << print.getName() << " Grade to sign " << print.getGradeSign() << std::endl
        << print.getName() << " Grade to execute " << print.getGradeExec() << std::endl
        << "Bureaucrat is signed? - " << print.getSign() << std::endl;
    return os;
}