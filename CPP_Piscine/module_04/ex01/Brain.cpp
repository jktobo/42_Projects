/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:55 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/11 13:30:46 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    _count = 0;
    std::cout << "Default constructor Brain called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy constructor Brain called" << std::endl;
    _count = other._count;
    for(int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
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

void Brain::setIdea(std::string str)
{
    _count++;
    _ideas[_count] = str;
}

void Brain::printIdeas() const
{
    if (_count > 0)
    {
        for (int i = 1; i <= _count; i++)
            std::cout << _ideas[i] << std::endl;
    }
    
}

Brain::~Brain()
{
    std::cout << "Destructor Brain called" << std::endl;
}