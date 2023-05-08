/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:46:20 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/08 15:59:34 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int intNum)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point = intNum << FB;
}

Fixed::Fixed(const float floatNum)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point = int(roundf(floatNum * (1 << FB)));
}

Fixed &Fixed::operator = (const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}


float Fixed::toFloat(void) const
{
    return float(fixed_point) / float(1 << FB); 
}

int Fixed::toInt( void ) const
{
    return (fixed_point >> FB);
}

std::ostream& operator<<(std::ostream &stream, const Fixed &print)
{
    stream << print.toFloat();
    return stream;
}