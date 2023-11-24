/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:54 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/24 15:06:57 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
    std::cerr << "You should enter numbers!" << std::endl;
    return (1);
    }
    
    std::vector<int> vec;
    std::deque<int> deq;
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        // std::cout << "Error: " << num << std::endl;
        if (num <= 0) {
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
    
    // PmergeMe<std::deque<int> > pmergeDeq;
    // double timeDeq_res = pmergeDeq.sort(deq);
    // pmergeDeq.printTime(timeDeq_res, deq.size(), "deque");

    return (0);
}


// jot -r 3000 1 100000 | xargs ./PmergeMe
// jot -r 30 1 100 | xargs ./PmergeMe