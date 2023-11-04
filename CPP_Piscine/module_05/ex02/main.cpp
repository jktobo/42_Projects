/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:32 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/04 11:14:46 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	// try
	// {
    //     Bureaucrat me("Zhun", 146); // все подписывает и выполняет. 140 - подпишет но не выполнит. 150 - не подпишет и не выполнит
    //     ShrubberyCreationForm form_sh("home"); // 145-sign, 137-exec
    //     std::cout << form_sh << std::endl;
    //     me.signForm(form_sh); // подписать shrubbery
    //     std::cout << std::endl << form_sh << std::endl;
	// 	form_sh.execute(me);
	// }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // std::cout << "-------------------------------------------" << std::endl;
	
    try
	{
        Bureaucrat me2("Denis", 40);
        RobotomyRequestForm form_rob("Roba");//72- sign, 45 -exec
        me2.signForm(form_rob);
        std::cout << std::endl << form_rob << std::endl;
		form_rob.execute(me2);
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

    
    return (0);

}