/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:43:56 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/01 13:06:41 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>

class Bureaucrat;
class Form
{
    private:
        std::string const _name;
        bool _sign;
        int const _gradeSign;
        int const _gradeExec; 
    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        ~Form();

        //Getters
        std::string getName();
        bool getSign();
        int getGradeSign();
        int getGradeExec();
        
        //Metods
        void beSigned(Bureaucrat &bureaucrat);
        
        //Created class for execption
        class GradeTooHighExeption : public std::exception {
            public:
                virtual const char *what() const throw(); 
        };
        class GradeTooLowExeption : public std::exception {
            public:
                virtual const char *what() const throw(); 
        };
};
	std::ostream& operator<<(std::ostream &os, const Form &print);

#endif