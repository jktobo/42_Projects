/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:21 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/04 14:26:41 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"


class AForm;
class Bureaucrat {

	private:
		std::string const _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();

		//Getters
		std::string getName() const;
		int getGrade() const;
		
		//Metods
		void incGrade();
		void decGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
	//Overload operator <<
	std::ostream& operator<<(std::ostream &os, const Bureaucrat &print);

#endif