#include "EasyFind.hpp"
#include <vector>
#include <list>
#include <array>

int main(void) {
    std::vector<int> vec;
    std::list<int> lis;
    std::array<int, 5> arr;
    // int arr[5];
    int findNum = 6;

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
        lis.push_back(i);
        arr[i] = i;
    }
    std::cout << std::endl;
    std::cout << "------====== VECTOR ======------" << std::endl;
    try
    {
        easyfind(vec, findNum);
    }
    catch(const std::exception& e)
    {
        std::cerr << "In VECTOR " << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "------====== LIST ======------" << std::endl;
    try
    {
        easyfind(lis, findNum);
    }
    catch(const std::exception& e)
    {
        std::cerr << "In LIST " << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "------====== ARRAY ======------" << std::endl;
    try
    {
        easyfind(arr, findNum);
    }
    catch(const std::exception& e)
    {
        std::cerr << "In ARRAY " << e.what() << '\n';
    }
    std::cout << std::endl;
    
    return (0);
}