/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:43:58 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/01 11:54:34 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>

// Form::Form(void) : _name("Default")
// {
	
// }

Form::Form(std::string const name, int const gradeSign, int const gradeExec) : _name(name), _sign(false), _gradeSign(gradeSign), _gradeExec(gradeExec){}

Form::~Form(){}

std::string Form::getName() {
	return _name;
}

bool Form::getSign() {
	return _sign;
}

int Form::getGradeSign() {
	return _gradeSign;
}

int Form::getGradeExec() {
	return _gradeExec;
}