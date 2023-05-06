/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:46:12 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/06 14:50:31 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixed_point;
        static const int FB = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator = (const Fixed &other);
        
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif