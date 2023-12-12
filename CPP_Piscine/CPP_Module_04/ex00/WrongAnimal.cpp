/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:10 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 14:45:12 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Default constructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& name)
{
    if (name.empty())
    {
        std::cout << "The parametre WrongAnimal can't be NULL!" << name << std::endl;
    }
    else
    {
        std::cout << "Constructor WrongAnimal with parameter called " << name << std::endl;
        _type = name;
    }
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "Copy constructor WrongAnimal called" << std::endl;
    _type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "Copy assignment operator WrongAnimal called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor WrongAnimal called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return _type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Makesound WrongAnimal called" << std::endl;
}