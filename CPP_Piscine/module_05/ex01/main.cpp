/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:26 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 09:53:29 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try
    {
        Form task("Fiscal", 80, 42);
		Bureaucrat buroc1("Burcat1",79);
		buroc1.signForm(task);
		std::cout << task;
		std::cout << buroc1;	
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}