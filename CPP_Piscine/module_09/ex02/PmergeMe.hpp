/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:18:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/24 20:11:34 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe {
    private:
        void InsertSort(std::vector<int> &vec);
        void MergeInsertSort(std::vector<int> &vec);

    public:
        PmergeMe();
        PmergeMe(PmergeMe const &copy);
        PmergeMe &operator=(PmergeMe const &other);
        
        // int checkDigitOrNot(std::string str);

        double vecSort(std::vector<int> &vec);
        void vecMergeInsertSort(std::vector<int> &vec);
        void  vecInsertSort(std::vector<int> &vec);

        double deqSort(std::deque<int> &deq);
        void deqMergeInsertSort(std::deque<int> &deq);
        void deqInsertSort(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deq);
        
        void printTime(double time_res, int contSize, std::string const contName);


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
