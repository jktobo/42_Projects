/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:53:10 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/13 14:53:12 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {

    Data data = {42, 4.42f, 's'};
    Data* ptr = &data;

    uintptr_t raw = 0;
    Data* deserialized;


    std::cout << std::endl;
    std::cout << "------====== BEFORE ======------" << std::endl;
    std::cout << "Address &Data\t" << &data << std::endl;
    std::cout << "Address *Ptr\t" << ptr << std::endl;
    std::cout << "Address Raw\t" << raw << std::endl;
    std::cout << "Address Deserialized\t" << deserialized << std::endl;
    std::cout << std::endl;
    std::cout << "------====== AFTER ======------" << std::endl;
    std::cout << std::endl;

    raw = Serializer::serialize(ptr);
    std::cout << "Address Raw\t" << raw << std::endl;

    deserialized = Serializer::deserialize(raw);
    std::cout << "Address Deserialized\t" << deserialized << std::endl;

    std::cout << std::endl;

    if (ptr == deserialized)
        std::cout << "Success!" << std::endl;
    else
        std::cout << "Fail!" << std::endl;
    return (0);
}