/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:46:08 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 14:46:09 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default constructor Cat called" << std::endl;
    _brain = new Brain();
}

// Cat::Cat(const std::string& name)
// {
//     if (name.empty())
//         std::cout << "The parametre Cat can't be empty!" << name << std::endl;
//     else
//     {
//         std::cout << "Constructor Cat with parameter called " << name << std::endl;
//         _type = name;
//         _brain = new Brain(name);
//     }
// }

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Copy constructor Cat called " << std::endl;
    // _type = other._type;
    // _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator Cat called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    if (_brain)
        delete _brain;
    std::cout << "Destructor Cat called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "MYEOYY!" << std::endl;
}