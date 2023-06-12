/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:22:58 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/11 17:29:51 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Default constructor AAnimal called" << std::endl;
}

// AAnimal::AAnimal(const std::string& name)
// {
//     if (name.empty())
//     {
//         std::cout << "The parametre AAnimal can't be NULL!" << name << std::endl;
//     }
//     else
//     {
//         std::cout << "Constructor AAnimal with parameter called " << name << std::endl;
//         _type = name;
//     }
// }

AAnimal::AAnimal(const AAnimal& other)
{
    std::cout << "Copy constructor AAnimal called" << std::endl;
    _type = other._type;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << "Copy assignment operator AAnimal called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor AAnimal called" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return _type;
}

// void AAnimal::makeSound(void) const
// {
//     std::cout << "Makesound AAnimal called" << std::endl;
// }