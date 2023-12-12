/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:47 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/25 21:53:41 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <stack>
#include <cstdlib>

class RPN {
    private:
        int checkDigitOrNot(std::string str);
        std::stack<int> stek;

    public:
        std::string _arg;
        RPN(RPN const &copy);
        RPN &operator=(RPN const &copy);
        RPN(std::string const arg);
        int calculate();
};

#endif