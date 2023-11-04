/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:46:14 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/04 14:29:19 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm Default constructor", 25, 5), _target("target") {
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _target(copy._target) {
    
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    AForm::operator=(other);
    _target = other._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    
}

void PresidentialPardonForm::execute(Bureaucrat &executor) const {
    if (!this->getSign())
        throw AForm::TheFormIsNotSigned();
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowExeption();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}