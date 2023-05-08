/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:46:34 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/08 16:06:11 by dkaratae         ###   ########.fr       */
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
};
std::ostream& operator<<(std::ostream &os, const Fixed &print);
#endif