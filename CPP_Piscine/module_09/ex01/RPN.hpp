/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:47 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/22 16:17:48 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <stack>

class RPN {
    private:
        std::string const _arg;
        std::stack<int> stek;

    public:
        RPN(std::string const arg);
        int calculate();
};

#endif