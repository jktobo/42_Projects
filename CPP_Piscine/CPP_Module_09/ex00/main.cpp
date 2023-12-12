/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:14 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/22 16:17:16 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "You should include Input file!" << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange btex;
        btex.loadCsv("data.csv");
        btex.inputTxt(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR! " << e.what() << '\n';
    }
    
    return(0);
}