/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:32 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 10:00:04 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat buroc1("Burcat1", 140);
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

    // try
	// {
    //     Bureaucrat me2("Denis", 40);
    //     RobotomyRequestForm form_rob("Roba");//72- sign, 45 -exec
    //     me2.signForm(form_rob);
    //     std::cout << std::endl << form_rob << std::endl;
	// 	form_rob.execute(me2);
	// }
	// catch (std::exception & ex)
	// {
	// 	std::cout << ex.what() << std::endl;
	// }


	// try
	// {
    //     Bureaucrat me3("Denis", 4);
    //     PresidentialPardonForm form_pres("Chelovek");//25- sign, 5 -exec
    //     me3.signForm(form_pres);
    //     me3.executeForm(form_pres);
    //     std::cout << std::endl << form_pres << std::endl;
	// 	form_pres.execute(me3);
	// }
	// catch (std::exception & ex)
	// {
	// 	std::cout << ex.what() << std::endl;
	// }
    // return (0);

}