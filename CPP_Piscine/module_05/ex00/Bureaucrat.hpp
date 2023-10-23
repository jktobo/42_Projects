/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:21 by dkaratae          #+#    #+#             */
/*   Updated: 2023/10/23 16:09:58 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>
#include <iostream>

class Bureaucrat {

	private:
		const std::string _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat &operator == (const Bureaucrat &other);
		~Bureaucrat();

		//Setters
		void setName(std::string name);
		void setGrade(int grade);

		//Getters
		std::string getName();
		int getGrade();
		
		//Metods
		void incGrade();
		void decGrade();
		
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
	std::ostream &operator << (std::ostream &os, const Bureaucrat &print);
#endif;