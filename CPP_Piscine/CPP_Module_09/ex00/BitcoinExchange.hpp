/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:03 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/25 19:46:27 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
    
        void deleteGaps(std::string &date, std::string &value);
        bool dateIsValid(const std::string &date);
        int valueIsDigit(const std::string &value);
        bool valueIsPositive(const std::string &value);
        bool valueIsNotBig(const std::string &value);
        std::string findClosestLowerDate(const std::string& date);
        void PrintResult(const std::string &date, const std::string &value, const float &floatNum);
    public: 
        BitcoinExchange();
        BitcoinExchange(const std::string fileCsv);
        BitcoinExchange(BitcoinExchange const &copy);
        BitcoinExchange &operator=(BitcoinExchange const &other);
        ~BitcoinExchange();

        void loadCsv(const std::string fileCsv);
        void inputTxt(const std::string &fileTxt);
        // void PrintMap();

        class FileNotOpen : public std::exception {
            public:
                const char *what() const throw();
        };
        class FileIsEmpty : public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif