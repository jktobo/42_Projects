/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:45:12 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 12:38:49 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
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
        class TheFileNotOpen : public std::exception {
            public:
                virtual const char *what() const throw(); 
        };
};
	std::ostream& operator<<(std::ostream &os, const AForm &print);

#endif