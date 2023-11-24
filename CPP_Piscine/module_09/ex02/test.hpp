
// #include "PmergeMe.hpp"

// int main(int argc, char **argv) {
//     if (argc < 2) {
//         std::cout << "Error: No arguments provided." << std::endl;
//         return 1;
//     }

//     std::vector<int> vec;
//     std::deque<int> deq;

//     for (int i = 1; i < argc; ++i) {
//         int num = std::atoi(argv[i]);
//         if (num <= 0) {
//             std::cout << "Error: Invalid argument." << std::endl;
//             return 1;
//         }
//         vec.push_back(num);
//         deq.push_back(num);
//     }

//     std::cout << "Before: ";
//     for (size_t i = 0; i < vec.size(); ++i) {
//         std::cout << vec[i] << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "After: ";
//     for (size_t i = 0; i < deq.size(); ++i) {
//         std::cout << deq[i] << " ";
//     }
//     std::cout << std::endl;

//     PmergeMe sorter;
//     std::chrono::duration<double> time_res;
//     time_res = sorter.sort(vec, deq);
//     sorter.printTimeDeque(vec, time_res);

//     return 0;
// }


// #include "PmergeMe.hpp"

// PmergeMe::PmergeMe() {}

// PmergeMe::~PmergeMe() {}

// PmergeMe::PmergeMe(const PmergeMe &other) {
//     *this = other;
// }

// PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
//     (void)other;
//     return *this;
// }

// std::chrono::duration<double> PmergeMe::sort(std::vector<int> &vec, std::deque<int> &deq) {
//     (void)vec;
//     std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
//     insertionSort(deq);
//     std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
//     return t2 - t1;

//     // t1 = std::chrono::high_resolution_clock::now();
//     // mergeSort(vec);
//     // t2 = std::chrono::high_resolution_clock::now();
//     // time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
//     // std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_span.count() << " us" << std::endl;
// }

// void PmergeMe::printTimeDeque(std::vector<int> &vec, std::chrono::duration<double> time_res) {
//     std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << time_res.count() << " us" << std::endl;
// }

// void PmergeMe::insertionSort(std::deque<int> &deq) {
//     for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
//         std::deque<int>::iterator insertion_point = std::upper_bound(deq.begin(), it, *it);
//         std::rotate(insertion_point, it, it + 1);
//     }
// }

// void PmergeMe::mergeSort(std::deque<int> &deq) {
//     if (deq.size() <= 1)
//         return;

//     std::deque<int> left, right;
//     for (size_t i = 0; i < deq.size(); ++i) {
//         if (i < deq.size() / 2)
//             left.push_back(deq[i]);
//         else
//             right.push_back(deq[i]);
//     }

//     mergeSort(left);
//     mergeSort(right);

//     merge(left, right, deq);
// }

// void PmergeMe::merge(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deq) {
//     std::deque<int>::iterator left_it = left.begin();
//     std::deque<int>::iterator right_it = right.begin();
//     std::deque<int>::iterator deq_it = deq.begin();

//     while (left_it != left.end() && right_it != right.end()) {
//         if (*left_it < *right_it) {
//             *deq_it = *left_it;
//             ++left_it;
//         } else {
//             *deq_it = *right_it;
//             ++right_it;
//         }
//         ++deq_it;
//     }

//     while (left_it != left.end()) {
//         *deq_it = *left_it;
//         ++left_it;
//         ++deq_it;
//     }

//     while (right_it != right.end()) {
//         *deq_it = *right_it;
//         ++right_it;
//         ++deq_it;
//     }
// }



// #ifndef PMERGEME_HPP
// #define PMERGEME_HPP

// #include <iostream>
// #include <vector>
// #include <deque>
// #include <chrono>
// #include <algorithm>
// #include <iterator>

// class PmergeMe {
// public:
//     PmergeMe();
//     ~PmergeMe();
//     PmergeMe(const PmergeMe &other);
//     PmergeMe &operator=(const PmergeMe &other);

//     // void sort(std::vector<int> &vec, std::deque<int> &deq);
//     std::chrono::duration<double> sort(std::vector<int> &vec, std::deque<int> &deq);

//     void printTimeDeque(std::vector<int> &vec, std::chrono::duration<double> time_res);


// private:
//     void insertionSort(std::deque<int> &deq);
//     void mergeSort(std::deque<int> &deq);
//     void merge(std::deque<int> &left, std::deque<int> &right, std::deque<int> &deq);
// };

// #endif
