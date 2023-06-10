/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:55 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 17:55:24 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor Brain called" << std::endl;
    _count = 0;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy constructor Brain called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy assignment operator Brain called" << std::endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

std::string *Brain::getIdeas()
{
    return _ideas;
}

void Brain::setIdeas(std::string str)
{
    _ideas[_count] = str;
    _count++;
}

void Brain::printIdeas()
{
    for (int i = 0; i < _count; i++)
    {
        std::cout << _ideas[i] << std::endl;
    }
}

Brain::~Brain()
{
    std::cout << "Destructor Brain called" << std::endl;
}