/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:46:49 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 15:37:16 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "Default constructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(const std::string& name)
{
    if (name.empty())
    {
        std::cout << "The parametre WrongCat can't be NULL!" << name << std::endl;
    }
    else
    {
        std::cout << "Constructor WrongCat with parameter called " << name << std::endl;
        _type = name;
    }
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "Copy constructor WrongCat called" << std::endl;
    // _type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "Copy assignment operator WrongCat called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor WrongCat called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "MYEOYY!" << std::endl;
}