/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:32 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 11:22:50 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat buroc1("Burcat1", 130);
    ShrubberyCreationForm Shrub_form("Garden");
	try
	{
        std::cout << Shrub_form << std::endl;
        buroc1.signForm(Shrub_form);
        std::cout << std::endl << Shrub_form << std::endl;
		Shrub_form.execute(buroc1);
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Bureaucrat buroc2("Burcat1", 73);
    // RobotomyRequestForm Robot_form("Garden");
	// try
	// {
    //     // std::cout << Robot_form << std::endl;
    //     buroc2.signForm(Robot_form);
    //     std::cout << std::endl << Robot_form << std::endl;
	// 	Robot_form.execute(buroc2);
	// }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // Bureaucrat buroc3("Burcat1", 3);
    // PresidentialPardonForm President_form("Garden");
	// try
	// {
    //     std::cout << President_form << std::endl;
    //     buroc3.signForm(President_form);
	// 	President_form.execute(buroc3);
    //     std::cout << std::endl << President_form << std::endl;
	// }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    return (0);
}