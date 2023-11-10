/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:11 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 09:27:08 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    
}

Intern::~Intern() {
    
}

AForm *Intern::runPresidentialForm(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::runRobotomyForm(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::runShrubberyForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {

    this->_formName[0] = "presidential request";
    this->_formName[1] = "robotomy request";
    this->_formName[2] = "shrubbery request";

    this->runForm[0] =  &Intern::runPresidentialForm;
    this->runForm[1] =  &Intern::runRobotomyForm;
    this->runForm[2] =  &Intern::runShrubberyForm;
    
    for (int i = 0; i <= 3; i++)
    {
        if (_formName[i] == formName) {
            return ((this->*runForm[i])(formTarget));
            std::cout << "Intern creates " << formName << std::endl;
        }
    }
    throw AForm::TheFormIsNotExist();
}