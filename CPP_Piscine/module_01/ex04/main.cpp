/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:50 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/24 20:02:30 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

// int main(int÷ argc, char **argv)
int main()
{
    std::string line = "Lorem Ipsum is text simply dummy text of the printing and text typesetting industry.";
    std::string str1 = "text";
    std::string str2 = "WORD";
    
    size_t pos = 0;
    while ((pos = line.find(str1, pos)) != std::string::npos) {
        line.erase(pos, str1.length());
        line.insert(pos, str2);
        pos += str2.length();
    }
    
    std::cout << line << std::endl;
    // if (argc != 4)
    // {
    //     std::cout << "Error! You should to enter 1 - file name, 2 - string1 and 3 - string2" << std::endl;
    //     return (1);
    // }
    // std::ifstream infile(argv[1]);
    // if (!(infile.is_open()))
    // {
    //     std::cout << "You should include file!" << std::endl;
    // }
    // std::string str;
    // size_t pos = 0;
    // std::getline(infile, str, '\0');
    // int len = str.length();
 
    // std::string str3 = argv[3];
    // while ((pos = str.find(argv[2])) != std::string::npos)
    // {
    //     std::cout << "find" << std::endl;
    //     std::cout << pos << std::endl;
    //     pos += str3.length();
    // }
    // std::cout << str << std::endl;
    
    
    return (0);
}