/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:36 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 17:13:42 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default constructor Animal called" << std::endl;
}

Animal::Animal(const std::string& name)
{
    if (name.empty())
    {
        std::cout << "The parametre Animal can't be NULL!" << name << std::endl;
    }
    else
    {
        std::cout << "Constructor Animal with parameter called " << name << std::endl;
        _type = name;
    }
}

Animal::Animal(const Animal& other)
{
    std::cout << "Copy constructor Animal called" << std::endl;
    _type = other._type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Copy assignment operator Animal called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal()
{
    if (_brain)
        delete _brain;
    std::cout << "Destructor Animal called" << std::endl;
}

std::string Animal::getType(void) const
{
    return _type;
}

void Animal::setIdeass(std::string str) const
{
    _brain->setIdeas(str);
}

void Animal::makeSound(void) const
{
    std::cout << "Makesound Animal called" << std::endl;
}