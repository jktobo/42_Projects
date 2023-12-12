/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:26 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 12:14:35 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    
    Form task("Fiscal", 80, 42);
    
    Bureaucrat buroc1("Burcat1",81);
    try
    {
		buroc1.signForm(task);
		std::cout << task;
		std::cout << buroc1;	
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // Bureaucrat buroc2("Burcat2",79);
    // try
    // {
	// 	buroc2.signForm(task);
	// 	std::cout << task;
	// 	std::cout << buroc2;	
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    return (0);
}