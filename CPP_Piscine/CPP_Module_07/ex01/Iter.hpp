/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:44:27 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/14 18:51:25 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define BLUE			"\033[34m"
#define WHITE			"\033[37m"
#define UNDERLINE		"\033[4m"
#define BOLD_UNDERLINE	"\033[1;4m"


template <typename T>
void red_show(T variable) {
    std::cout << RED << variable << std::endl;
}
template <typename T>
void blue_show(T variable) {
    std::cout << BLUE << variable << std::endl;
}
template <typename T>
void green_show(T variable) {
    std::cout << GREEN << variable << std::endl;
}
template <typename T>
void yellow_show(T variable) {
    std::cout << YELLOW << variable << std::endl;
}

// void iter(T *array, size_t size, void (*func)(const T &x)) {
        // (*func)(array[i]);
template <typename T, typename F>
void iter(T *array, size_t size, F func) {
    if (!size)
        return ;
    for(size_t i = 0; i < size; i++) {
        func(array[i]);
    }
}

#endif