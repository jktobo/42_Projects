/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:37 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 11:44:30 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
	Intern student_intern;
    AForm * form;
        
    Bureaucrat buroc1("Burcat1", 20);
	try
	{
	    form = student_intern.makeForm("robotomy request", "Bender");
        std:: cout << *form << std::endl;
        buroc1.signForm(*form);
        std:: cout << *form << std::endl;
		form->execute(buroc1);
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
        return (0);
	}
	
    // Bureaucrat buroc2("Burcat2", 136);
	// try
	// {
	//     form = student_intern.makeForm("shrubbery request", "Bender");
    //     std:: cout << *form << std::endl;
    //     buroc2.signForm(*form);
    //     std:: cout << *form << std::endl;
	// 	form->execute(buroc2);
	// }
	// catch (std::exception & ex)
	// {
	// 	std::cout << ex.what() << std::endl;
    //     return (0);
	// }
	
    // Bureaucrat buroc3("Burcat3", 20);
	// try
	// {
	//     form = student_intern.makeForm("presidential request", "Bender");
    //     std:: cout << *form << std::endl;
    //     buroc3.signForm(*form);
    //     std:: cout << *form << std::endl;
	// 	form->execute(buroc3);
	// }
	// catch (std::exception & ex)
	// {
	// 	std::cout << ex.what() << std::endl;
    //     return (0);
	// }

    delete form;
    return (0);
}