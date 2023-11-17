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