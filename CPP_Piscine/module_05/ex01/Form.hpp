/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:43:56 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/03 15:07:45 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <istream>
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
        Form(Form const &copy);
        Form &operator=(Form &other);
        ~Form();

        //Getters
        std::string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExec() const;
        
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