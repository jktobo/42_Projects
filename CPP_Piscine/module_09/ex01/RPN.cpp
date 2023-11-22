/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:41 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/22 16:17:43 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const arg) : _arg(arg) {}

int checkDigitOrNot(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}
int RPN::calculate() {
    std::istringstream iss(_arg);
    std::string arg_l;

    while (iss >> arg_l) {
        if (checkDigitOrNot(arg_l)) {
            stek.push(std::stoi(arg_l));
        } else {
            if (stek.size() < 2) {
                throw std::runtime_error("Uncorect the argument!");
            }
            int top1  = stek.top();
            stek.pop();
            int top2  = stek.top();
            stek.pop();
            if (arg_l[0] == '+')
                stek.push(top2 + top1);
            else if (arg_l[0] == '-')
                stek.push(top2 - top1);
            else if (arg_l[0] == '*')
                stek.push(top2 * top1);
            else if (arg_l[0] == '/') {
                if (top1 == 0)
                    throw std::runtime_error("Cannot to divide by 0");
                stek.push(top2 / top1);
            } else
                throw std::runtime_error("Uncorrect the operator");
        }
    }
    if (stek.size() != 1)
        throw std::runtime_error("Uncorrect the argument");
    return stek.top();
}

