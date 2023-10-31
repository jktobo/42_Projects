/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:43:56 by dkaratae          #+#    #+#             */
/*   Updated: 2023/10/31 13:23:12 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form
{
private:
    std::string const _name;
    bool _sign;
    int const gradeSign;
    int const gradeExec; 
public:
    Form(/* args */);
    ~Form();

    class GradeTooHighExeption : public std::exception {
        public:
            virtual const char *what() const throw(); 
    };
};

#endif