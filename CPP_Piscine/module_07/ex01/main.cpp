#include "Iter.hpp"

int main(void) {

    std::cout << "------======INT======-------" << std::endl;
    int arr_i[] = {5, 7, 3, 9, 8};
    size_t size = sizeof(arr_i) / sizeof(arr_i[0]);
    iter(arr_i, size, red_show<int>);

    std::cout << "------======DOUBLE======-------" << std::endl;
    double arr_d[] = {5.5, 7.6, 3.8, 9.0, 8.4};
    size = sizeof(arr_d) / sizeof(arr_d[0]);
    iter(arr_d, size, green_show<double>);

    std::cout << "------======STRING======-------" << std::endl;
    std::string arr_s[] = {"Dubai", "Abu-Dhabi", "Bishkek", "New-Yourk", "Paris"};
    size = sizeof(arr_s) / sizeof(arr_s[0]);
    iter(arr_s, size, blue_show<std::string>);


    return (0);
}