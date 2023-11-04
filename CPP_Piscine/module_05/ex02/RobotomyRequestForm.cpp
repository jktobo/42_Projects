/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:46:19 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/04 11:31:44 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm Default constructor", 72, 45), _target("target") {
    
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy._target) {
    
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    AForm::operator=(other);
    _target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const {

    if (!this->getSign())
        throw AForm::TheFormIsNotSigned();
        // throw "The RobotomyRequestForm isn't signed!!!";
    // std::cout << "executor.getGrade\t" << executor.getGrade()<< std::endl <<
    // "this->getGradeExec\t" << this->getGradeExec() << std::endl;
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowExeption();
    
    srand(time(0));
    if (rand() % 2) {
        std::cout << "Drrrrriiilllinggggggggg.........ggggggggg.gg.g!" << std::endl;
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    } else
        std::cout << "Failed, it has not been robotomized" << std::endl;
}