/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:46:17 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 14:46:19 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default constructor Dog called" << std::endl;
    _brain = new Brain();
}

// Dog::Dog(const std::string& name)
// {
//     if (name.empty())
//     {
//         std::cout << "The parametre Dog can't be empty!" << name << std::endl;
//     }
//     else
//     {
//         std::cout << "Constructor Dog with parameter called " << name << std::endl;
//         _type = name;
//         _brain = new Brain(name);
//     }
// }

Dog::Dog(const Dog& other) : Animal(other)//, _brain(new Brain(*other._brain))
{
    std::cout << "Copy constructor Dog called" << std::endl;
    _type = other._type;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator Dog called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog()
{
    if (_brain)
        delete _brain;
    std::cout << "Destructor Dog called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "WOOF!" << std::endl;
}