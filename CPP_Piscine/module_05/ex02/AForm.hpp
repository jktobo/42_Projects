/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:45:12 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/09 23:59:02 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <istream>
#include <string>

class Bureaucrat;
class AForm
{
    private:
        std::string const _name;
        bool _sign;
        int const _gradeSign;
        int const _gradeExec; 
    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        AForm(AForm const &copy);
        AForm &operator=(AForm const &other);
        ~AForm();

        //Getters
        std::string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExec() const;
        
        //Metods
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat &executor) const = 0;
        
        //Created class for execption
        class GradeTooHighExeption : public std::exception {
            public:
                virtual const char *what() const throw(); 
        };
        class GradeTooLowExeption : public std::exception {
            public:
                virtual const char *what() const throw(); 
        };
        class TheFormIsNotSigned : public std::exception {
            public:
                virtual const char *what() const throw(); 
        };
};
	std::ostream& operator<<(std::ostream &os, const AForm &print);

#endif