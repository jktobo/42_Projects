/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:54 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/26 14:37:55 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
    std::cerr << "You should enter numbers!" << std::endl;
    return (1);
    }
    size_t size = argc;
    for (size_t i = 1; i < size; ++i) {
        for (size_t j = 0; argv[i][j]; ++j) {
            if (!isdigit(argv[i][j])) {
                std::cout << "ERROR: You shoud enter only numbers!" << std::endl;
                return 1;
            }
        }
    }
    
    std::vector<int> vec;
    std::deque<int> deq;
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        // if (num < 1 && !isdigit(num)) {
        if (num < 0 && !isdigit(num)) {
            std::cout << "Error: You didn't enter numbers!" << std::endl;
            return (1);
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    std::cout << "Before:  ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    PmergeMe pmergeVec;
    double timeVec_res = pmergeVec.vecSort(vec);
    std::cout << "After:   ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    pmergeVec.printTime(timeVec_res, vec.size(), "vector");
    
    PmergeMe pmergeDeq;
    double timeDeq_res = pmergeDeq.deqSort(deq);
    // std::cout << "After:   ";
    // for (size_t i = 0; i < deq.size(); ++i) {
    //     std::cout << deq[i] << " ";
    // }
    // std::cout << std::endl;
    pmergeDeq.printTime(timeDeq_res, deq.size(), "deque");

    return (0);
}


// jot -r 3000 1 100000 | xargs ./PmergeMe
// jot -r 30 1 100 | xargs ./PmergeMe