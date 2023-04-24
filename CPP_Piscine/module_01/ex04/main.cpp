/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:50 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/24 18:41:55 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error! You should to enter 1 - file name, 2 - string1 and 3 - string2" << std::endl;
        return (1);
    }
    std::ifstream infile(argv[1]);
    if (!(infile.is_open()))
    {
        std::cout << "You should include file!" << std::endl;
    }
    std::string str;
    size_t pos = 0;
    std::getline(infile, str, '\0');
    int len = str.length();
 
    std::string str3 = argv[3];
    while ((pos = str.find(argv[2])) != std::string::npos)
    {
        std::cout << "find" << std::endl;
        std::cout << pos << std::endl;
        pos += str3.length();
    }
    // std::cout << str << std::endl;
    
    
    return (0);
}