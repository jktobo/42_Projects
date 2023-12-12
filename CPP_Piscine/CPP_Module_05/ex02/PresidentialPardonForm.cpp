/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:46:14 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 11:52:19 by dkaratae         ###   ########.fr       */
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