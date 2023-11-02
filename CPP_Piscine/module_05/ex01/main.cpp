/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:42:26 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/02 16:43:19 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try
    {
        // Form a("A", 0, 100);
        Form A("Security", 80, 42);
		Bureaucrat B("Jen",79);
		B.signForm(A);
		std::cout << A;
		std::cout << B;	
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}