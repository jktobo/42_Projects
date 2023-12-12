/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:46:32 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/13 14:57:17 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int intNum)
{
    // std::cout << "Int constructor called" << std::endl;
    fixed_point = intNum << FB;
}

Fixed::Fixed(const float floatNum)
{
    // std::cout << "Float constructor called" << std::endl;
    fixed_point = int(roundf(floatNum * (1 << FB)));
}

Fixed &Fixed::operator = (const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
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

// The 6 comparison operators: >, <, >=, <=, == and !=.

bool Fixed::operator > (const Fixed &other) const
{
    if (this->fixed_point > other.fixed_point)
        return true;
    else
        return false;
}

bool Fixed::operator < (const Fixed &other) const
{
    if (this->fixed_point < other.fixed_point)
        return true;
    else
        return false;
}

bool Fixed::operator >= (const Fixed &other) const
{
    if (this->fixed_point >= other.fixed_point)
        return true;
    else
        return false;
}

bool Fixed::operator <= (const Fixed &other) const
{
    if (this->fixed_point <= other.fixed_point)
        return true;
    else
        return false;
}

bool Fixed::operator == (const Fixed &other) const
{
    if (this->fixed_point == other.fixed_point)
        return true;
    else
        return false;
}

bool Fixed::operator != (const Fixed &other) const
{
    if (this->fixed_point == other.fixed_point)
        return true;
    else
        return false;
}

// The 4 arithmetic operators: +, -, *, and /.

Fixed Fixed::operator + (const Fixed &other)
{
    Fixed plus(this->toFloat() + other.toFloat());
    return plus;
}

Fixed Fixed::operator - (const Fixed &other)
{
    Fixed subtract(this->toFloat() - other.toFloat());
    return subtract;
}

Fixed Fixed::operator * (const Fixed &other)
{
    Fixed multiply(this->toFloat() * other.toFloat());
    return multiply;
}

Fixed Fixed::operator / (const Fixed &other)
{
    Fixed division(this->toFloat() / other.toFloat());
    return division;
}

// The 4 increment/decrement

Fixed& Fixed::operator ++ () // prefix increment
{
    this->fixed_point++;
    return *this;
}

Fixed Fixed::operator ++ (int) // postfix increment
{
    Fixed temp(*this);
    this->fixed_point++;
    return temp;
}

Fixed& Fixed::operator -- () // prefix decrement
{
    this->fixed_point--;
    return *this;
}

Fixed Fixed::operator -- (int) // postfix decrement
{
    Fixed temp(*this);
    this->fixed_point--;
    return temp;
}

// min, max, const min, const max

Fixed& Fixed::min(Fixed &arg1, Fixed &arg2)
{
    if (arg1 < arg2)
        return arg1;
    else
        return arg2;
}

Fixed& Fixed::max(Fixed &arg1, Fixed &arg2)
{
    if (arg1 > arg2)
        return arg1;
    else
        return arg2;
}

const Fixed& Fixed::min(const Fixed &arg1, const Fixed &arg2)
{
    if (arg1 < arg2)
        return arg1;
    else
        return arg2;
}

const Fixed& Fixed::max(const Fixed &arg1, const Fixed &arg2)
{
    if (arg1 > arg2)
        return arg1;
    else
        return arg2;
}