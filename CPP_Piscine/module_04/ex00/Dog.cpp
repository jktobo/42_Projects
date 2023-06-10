/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:44:55 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 14:44:57 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default constructor Dog called" << std::endl;
}

Dog::Dog(const std::string& name)
{
    if (name.empty())
    {
        std::cout << "The parametre Dog can't be empty!" << name << std::endl;
    }
    else
    {
        std::cout << "Constructor Dog with parameter called " << name << std::endl;
        _type = name;
    }
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Copy constructor Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator Dog called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor Dog called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "WOOF!" << std::endl;
}