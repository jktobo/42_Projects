/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:44:46 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/14 18:44:47 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    private:
        T *_array;
        unsigned int _n;
    public:
        Array() : _n(0), _array(0) {

        }
        Array(unsigned int n) {
            _array = new T[n];
            _n = n;
        }
        Array(Array const &copy) {
            this->_array = new T[copy._n];
            _n = copy._n;
            for (unsigned int i = 0; i < _n; i++) {
                this->_array[i] = copy._array[i];
            }
        }
        Array &operator=(Array const &other) {
            if (this != &other) {
                delete[] _array;
                _n = other._n;
                _array = new T[_n];
                for (unsigned int i = 0; i < _n; i++) {
                    this->_array[i] = other._array[i];
                }
            }
            return (*this);
        }

        ~Array() {
            delete[] _array;
        }

        T &operator[](unsigned int index) {
            if (index >= _n || index < 0) {
                throw std::out_of_range("The Index is out of bounds");
            }
            return (_array[index]);
        }

        unsigned int size() {
            return (_n);
        }
};

#endif