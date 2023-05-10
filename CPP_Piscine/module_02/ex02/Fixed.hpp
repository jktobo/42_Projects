/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:46:34 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/10 13:21:15 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int FB = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed(const int intNum);
        Fixed(const float floatNum);
        Fixed &operator = (const Fixed &other);
        
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
        bool operator > (const Fixed& other)const;
        bool operator < (const Fixed& other)const;
        bool operator >= (const Fixed& other)const;
        bool operator <= (const Fixed& other)const;
        bool operator == (const Fixed& other)const;
        bool operator != (const Fixed& other)const;

        Fixed operator + (const Fixed &other);
        Fixed operator - (const Fixed &other);
        Fixed operator * (const Fixed &other);
        Fixed operator / (const Fixed &other);
        
        Fixed &operator ++ ();
        Fixed operator ++ (int);
        Fixed &operator -- ();
        Fixed operator -- (int);

        static Fixed &min(Fixed &arg1, Fixed &arg2);
        static Fixed &max(Fixed &arg1, Fixed &arg2);
        static const Fixed &min(const Fixed &arg1, const Fixed &arg2);
        static const Fixed &max(const Fixed &arg1, const Fixed &arg2);

};
std::ostream& operator<<(std::ostream &os, const Fixed &print);

#endif