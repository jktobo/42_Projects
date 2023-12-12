/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:46:24 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 12:53:11 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm Default constructor", 145, 137), _target("target") {
    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) {
    
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    AForm::operator=(other);
    _target = other._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const {

    std::string fileName = _target + "_shrubbery";
    if (!this->getSign())
        throw AForm::TheFormIsNotSigned();
    // throw "The ShrubberyCreationForm isn't signed!!!";
    // std::cout << "executor.getGrade\t" << executor.getGrade()<< std::endl <<
    // "this->getGradeExec\t" << this->getGradeExec() << std::endl;
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowExeption();
    
    std::ofstream ofs(fileName.c_str());
    if (!ofs.is_open()) {
        throw AForm::TheFileNotOpen();
    }
    ofs << "                                            .\n\
                                              .         ;  \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'     .,   \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'   \n\
                        `@%.  `;@%.      ;@@%;        \n\
                          `@%%. `@%%    ;@@%;        \n\
                            ;@%. :@%%  %@@%;       \n\
                              %@bd%%%bd%%:;     \n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '         \n\
                                %@@@o%;:(.,'         \n\
                            `.. %@@@o%::;         \n\
                               `)@@@o%::;         \n\
                                %@@(o)::;        \n\
                               .%@@@@%::;         \n\
                               ;%@@@@%::;.          \n\
                              ;%@@@@%%:;;;. \n\
                          ...;%@@@@@%%:;;;;,.." << std::endl;
    ofs.close();
}
