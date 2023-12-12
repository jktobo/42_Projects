/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:52:56 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/17 20:37:50 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T> {
    public:
        MutantStack() : std::stack<T>() {

        }
        MutantStack(const MutantStack &copy) : std::stack<T>(copy) {

        }
        MutantStack &operator=(const MutantStack &other) {
            if (this != &other) {
                std::stack<T>::operator=(other);
            }
            return (*this);
        }
        ~MutantStack() {

        }
        // typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename container::iterator iterator;
        iterator begin() {
            return (std::stack<T>::c.begin());
        }
        iterator end() {
            return (std::stack<T>::c.end());
        }
};

#endif