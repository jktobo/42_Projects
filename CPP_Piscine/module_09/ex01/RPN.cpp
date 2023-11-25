/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:41 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/25 22:08:45 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const arg) : _arg(arg) {}


RPN::RPN(RPN const &copy) {
    *this = copy;
}
RPN &RPN::operator=(RPN const &other) {
    // if (*this != other) {
        this->_arg = other._arg;
        this->stek = other.stek;
    // }
    return(*this);
}


int RPN::checkDigitOrNot(std::string str) {
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

            try {
                int c_num = atoi(arg_l.c_str());
                if (c_num > 9)
                    throw std::runtime_error("Value greater than 9");
                stek.push(c_num);
            } catch (std::invalid_argument& e) {
                std::cerr << "ERROR! Invalid argument: " << arg_l << std::endl;
            } catch (std::out_of_range& e) {
                std::cerr << "ERROR! Out of range: " << arg_l << std::endl;
            }
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
                    throw std::runtime_error("Can't to divide by 0");
                stek.push(top2 / top1);
            } else
                throw std::runtime_error("Uncorrect the operator");
        }
    }
    if (stek.size() != 1)
        throw std::runtime_error("Uncorrect the argument");
    return stek.top();
}

