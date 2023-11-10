/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:09 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 00:09:26 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
    Intern();
    ~Intern();

    AForm *makeForm(std::string formName, std::string targetForm);
    AForm *runPresidentialForm(std::string targetForm);
    AForm *runRobotomyForm(std::string targetForm);
    AForm *runShrubberyForm(std::string targetForm);
    
    
    private:
    
        std::string _formName[3];
        AForm *(Intern::*runForm[3])(std::string targetName);
        // const std::string _formName[3] = {
        //     "presidential request",
        //     "robotomy request",
        //     "shrubbery request"
        // };

        // AForm *(Intern::*runForm[3])(std::string targetName) = {
        //     &Intern::runPresidentialForm,
        //     &Intern::runRobotomyForm,
        //     &Intern::runShrubberyForm
        // };
        // https://learn.microsoft.com/ru-ru/troubleshoot/developer/visualstudio/cpp/language-compilers/declare-pointers-to-functions
        
};

#endif