/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:18:02 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/24 16:18:31 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &copy) {*this = copy;}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
    (void)other;
    return (*this);
}

double PmergeMe::vecSort(std::vector<int> &vec) {
    clock_t	start, finish;
    start = clock();
    vecMergeInsertSort(vec);
    finish = clock();
    return ((double) (finish - start) / CLOCKS_PER_SEC);
}

void PmergeMe::vecMergeInsertSort(std::vector<int> &vec) {
    if (vec.size() <= 5) {
        vecInsertSort(vec);
    } else {
        std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
        std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());
        vecMergeInsertSort(left);
        vecMergeInsertSort(right);
        vec.clear();
        std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vec));
    }
}

void  PmergeMe::vecInsertSort(std::vector<int> &vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::printTime(double time_res, int contSize, std::string const contName) {
    std::cout << "Time to process a range of " << contSize << " elements with std::" << contName << " :\t" << time_res << " us" << std::endl;
}


double PmergeMe::deqSort(std::deque<int> &deq) {
    clock_t	start, finish;
    start = clock();
    deqMergeInsertSort(deq);
    finish = clock();
    return ((double) (finish - start) / CLOCKS_PER_SEC);
}


void PmergeMe::deqMergeInsertSort(std::deque<int> &deq) {
    if (deq.size() <= 1)
        return;

    std::deque<int> left, right;
    for (size_t i = 0; i < deq.size(); ++i) {
        if (i < deq.size() / 2)
            left.push_back(deq[i]);
        else
            right.push_back(deq[i]);
    }

    deqMergeInsertSort(left);
    deqMergeInsertSort(right);

    deqInsertSort(left, right, deq);
}

void PmergeMe::deqInsertSort(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deq) {
    std::deque<int>::iterator left_it = left.begin();
    std::deque<int>::iterator right_it = right.begin();
    std::deque<int>::iterator deq_it = deq.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it < *right_it) {
            *deq_it = *left_it;
            ++left_it;
        } else {
            *deq_it = *right_it;
            ++right_it;
        }
        ++deq_it;
    }

    while (left_it != left.end()) {
        *deq_it = *left_it;
        ++left_it;
        ++deq_it;
    }

    while (right_it != right.end()) {
        *deq_it = *right_it;
        ++right_it;
        ++deq_it;
    }
}





// void PmergeMe::deqInsertionSort(std::deque<int> &deq) {
//     for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
//         std::deque<int>::iterator insertion_point = std::upper_bound(deq.begin(), it, *it);
//         std::rotate(insertion_point, it, it + 1);
//     }
// }




// #include "PmergeMe.hpp"


//     // clock_t	start, finish;

// template <typename Container>
// PmergeMe<Container>::PmergeMe() {}

// template <typename Container>
// PmergeMe<Container>::~PmergeMe() {}

// template <typename Container>
// PmergeMe<Container>::PmergeMe(PmergeMe const &copy) {*this = copy;}

// template <typename Container>
// PmergeMe<Container> &PmergeMe<Container>::operator=(PmergeMe const &other) {
//     (void)other;
//     return (*this);
// }

// template <typename Container>
// std::chrono::duration<double> PmergeMe<Container>::sort(Container &container) {
//     std::chrono::high_resolution_clock::time_point timeStart = std::chrono::high_resolution_clock::now();
//     MergeInsertSort(container);
//     std::chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();
//     return (timeEnd - timeStart);
// }

// template <typename Container>
// void PmergeMe<Container>::MergeInsertSort(Container &container) {
//     if (container.size() <= 5) {
//         InsertSort(container);
//     } else {
//         Container left(container.begin(), container.begin() + container.size() / 2);
//         Container right(container.begin() + container.size() / 2, container.end());
//         MergeInsertSort(left);
//         MergeInsertSort(right);
//         container.clear();
//         std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(container));
//     }
// }

// template <typename Container>
// void  PmergeMe<Container>::InsertSort(Container &container) {
//     for (size_t i = 1; i < container.size(); ++i) {
//         int key = container[i];
//         int j = i - 1;
//         while (j >= 0 && container[j] > key) {
//             container[j + 1] = container[j];
//             --j;
//         }
//         container[j + 1] = key;
//     }
// }

// template <typename Container>
// void PmergeMe<Container>::printTime(std::chrono::duration<double> time_res, int contSize, std::string const contName) {
//     std::cout << "Time to process a range of " << contSize << " elements with std::" << contName << " :\t" << time_res.count() << " us" << std::endl;
// }

// template class PmergeMe<std::vector<int> >;
// template class PmergeMe<std::deque<int> >;
