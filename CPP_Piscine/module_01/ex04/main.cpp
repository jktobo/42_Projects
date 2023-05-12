/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:50 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/11 18:29:18 by dkaratae         ###   ########.fr       */
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
        // return (1);
    }
    else
    {
        std::string fileName = argv[1];
        std::string str1 = argv[2];
        std::string str2 = argv[3];
        std::ifstream infile(fileName);
        if (!(infile.is_open()))
        {
            std::cout << "You should include file!" << std::endl;
        }
        size_t pos = 0;
        std::string line;
        std::getline(infile, line, '\0');
        infile. close();
        while ((pos = line.find(str1, pos)) != std::string::npos) {
            line.erase(pos, str1.length());
            line.insert(pos, str2);
            pos += str2.length();
        }
        std::ofstream replaceFile;
        if (!replaceFile)
        {
            std::cout << "ERROR! The wasn't create!" << std::endl;
            return (1);
        }
        replaceFile.open(fileName + ".replace");
        replaceFile << line;
        replaceFile.close();
    }
    return (0);
}