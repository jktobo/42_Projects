/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:18:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/24 15:27:12 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <chrono>

class PmergeMe {
    private:
        void InsertSort(std::vector<int> &vec);
        void MergeInsertSort(std::vector<int> &vec);

    public:
        PmergeMe();
        PmergeMe(PmergeMe const &copy);
        PmergeMe &operator=(PmergeMe const &other);
        
        double vecSort(std::vector<int> &vec);
        void vecMergeInsertSort(std::vector<int> &vec);
        void  vecInsertSort(std::vector<int> &vec);

        void PmergeMe::deqInsertionSort(std::deque<int> &deq)ж
        
        
        void printTime(double time_res, int contSize, std::string const contName);

        std::chrono::duration<double> sortDeq(std::vector<int> &vec);

        ~PmergeMe();
};
#endif








// #ifndef PMERGEME_HPP
// #define PMERGEME_HPP

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <deque>
// #include <chrono>

// template <typename Container>
// class PmergeMe {
//     private:
//         void InsertSort(Container &container);
//         void MergeInsertSort(Container &container);

//     public:
//         PmergeMe();
//         PmergeMe(PmergeMe const &copy);
//         PmergeMe &operator=(PmergeMe const &other);
//         double sort(Container &container);
//         void printTime(double time_res, int contSize, std::string const contName);

//         std::chrono::duration<double> sortDeq(Container &container);

//         ~PmergeMe();
// };
// #endif
