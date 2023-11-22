#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        void deleteGaps(std::string &date, std::string &value);
        bool dateIsValid(const std::string &date);
        bool valueIsPositive(const std::string &value);
        bool valueIsNotBig(const std::string &value);
        std::string findClosestLowerDate(const std::string& date);
        void PrintResult(const std::string &date, const std::string &value, const float &floatNum);

    public: 
        BitcoinExchange();
        BitcoinExchange(const std::string fileCsv);
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