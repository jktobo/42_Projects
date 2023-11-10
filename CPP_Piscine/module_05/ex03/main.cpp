/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:37 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/10 09:31:12 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
    
    Bureaucrat me("Denis", 20);

	Intern a;
    AForm * f;
        
	try
	{
	    f = a.makeForm("robotomy request", "sweet"); // стажер создал новую форму robotomy
        std:: cout << *f << std::endl; //далее тут проверяем просто что реально она существует
        me.signForm(*f);
		f->execute(me);
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
        return (0);
	}
    delete f;
    return (0);
}