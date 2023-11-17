/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:52:31 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/17 18:52:33 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>


class Span {
    private:
        unsigned int _num;
        std::vector<int> _vec;
    public:
        Span();
        Span (unsigned int num);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &other);
        void addNumber(unsigned int value);
        int shortestSpan();
        int longestSpan();
        void addRandomNumbers(unsigned int count);
        void printSpan();
        class SpanIsFull : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class SpanSizeLess : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class SpanSizeNotEnough : public std::exception {
            public:
                virtual const char *what() const throw();
        };


};

#endif