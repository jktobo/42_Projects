#include "Serializer.hpp"
#include <iostream>

int main() {

    Data data = {42, 4.42f, 's'};
    Data* ptr = &data;

    uintptr_t serialized = 0;
    Data* deserialized;


    std::cout << std::endl;
    std::cout << "Address &Data\t" << &data << std::endl;
    std::cout << "Address *Ptr\t" << ptr << std::endl;
    std::cout << "Address Raw\t" << serialized << std::endl;
    std::cout << "Address Deserialized\t" << deserialized << std::endl;
    std::cout << std::endl;
    std::cout << "------====== AFTER ======------" << std::endl;
    std::cout << std::endl;

    serialized = Serializer::serialize(ptr);
    std::cout << "Address Raw\t" << serialized << std::endl;

    deserialized = Serializer::deserialize(serialized);
    std::cout << "Address Deserialized\t" << deserialized << std::endl;

    std::cout << std::endl;

    if (ptr == deserialized)
        std::cout << "Success!" << std::endl;
    else
        std::cout << "Fail!" << std::endl;
    return (0);
}