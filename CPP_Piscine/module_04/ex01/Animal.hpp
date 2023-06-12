/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:41 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/11 14:30:37 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
    Animal();
    Animal(const std::string& name);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    std::string getType(void) const;
    virtual void makeSound() const;
    protected:
        std::string _type;
};
#endif