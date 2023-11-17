/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:52:00 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/17 18:52:01 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class ElementNotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "element not found";
    }
};

template <typename T>
void easyfind(T &cont, int n) {
    typename T::iterator res = std::find(cont.begin(), cont.end(), n);
    
    if (res != cont.end())
        std::cout << "There is this number: " << *res << std::endl;
    else
        throw ElementNotFoundException();
}

#endif