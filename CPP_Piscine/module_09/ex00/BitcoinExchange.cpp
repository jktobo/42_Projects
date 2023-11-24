/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:16:55 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/24 19:47:10 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange:: BitcoinExchange() {
}

void BitcoinExchange::PrintResult(const std::string &date, const std::string &value, const float &floatNum) {
    std::string closestDate = findClosestLowerDate(date);
    float exchangeRate = data.at(closestDate);
    float result = floatNum * exchangeRate;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::loadCsv(const std::string fileCsv) {
    std::ifstream file(fileCsv.c_str());
    if (!file) {
        throw FileNotOpen();
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        throw FileIsEmpty();
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss (line);
        std::string date, value;
        if (std::getline(iss, date, ',') && std::getline(iss, value)) {
            try {
                data[date] = atof(value.c_str());
            } catch (std::invalid_argument& e) {
                std::cerr << "ERROR! Invalid argument: " << value << std::endl;
            } catch (std::out_of_range& e) {
                std::cerr << "ERROR! Out of range: " << value << std::endl;
            }
        }
    }
    file.close();
    // PrintMap();
}

void BitcoinExchange::inputTxt(const std::string &fileTxt) {
    std::ifstream file(fileTxt.c_str());

    if (!file.is_open()) {
        throw FileNotOpen();
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss (line);
        std::string date, value;
        if (std::getline(iss, date, '|') && std::getline(iss, value)) {
            deleteGaps(date, value);
            if (!dateIsValid(date)) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (!valueIsPositive(value)) {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (!valueIsNotBig(value)) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            float floatNum = 0;
            try {
                floatNum = atof(value.c_str());
            } catch (std::invalid_argument& e) {
                std::cerr << "ERROR! Invalid argument: " << value << std::endl;
            } catch (std::out_of_range& e) {
                std::cerr << "ERROR! Out of range: " << value << std::endl;
            }
            PrintResult(date, value, floatNum);
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
}

std::string BitcoinExchange::findClosestLowerDate(const std::string& date) {
    std::map<std::string, float>::iterator it = data.lower_bound(date);
    if (it == data.begin() && it->first != date) {
        return "";
    }
    if (it->first != date) {
        --it;
    }
    return it->first;
}

void BitcoinExchange::deleteGaps(std::string &date, std::string &value) {
    date.erase(0, date.find_first_not_of(" "));
    date.erase(date.find_last_not_of(" ") + 1);
    value.erase(0, value.find_first_not_of(" "));
    value.erase(value.find_last_not_of(" ") + 1);
}

// bool BitcoinExchange::dateIsValid(const std::string &date) {
//     std::tm tm = {};
//     std::istringstream ss(date);
//     ss >> std::get_time(&tm, "%Y-%m-%d");
//     if (ss.fail()) {
//         return false;
//     }
//     tm.tm_isdst = -1;
//     std::mktime(&tm);
//     return tm.tm_year + 1900 == std::atoi(date.substr(0, 4).c_str()) &&
//            tm.tm_mon + 1 == std::atoi(date.substr(5, 2).c_str()) &&
//            tm.tm_mday == atoi(date.substr(8, 2).c_str());
// }

bool BitcoinExchange::dateIsValid(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (month == 2) {
        bool isLeap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
        if ((day > 29) || (day == 29 && !isLeap)) {
            return false;
        }
    }
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    return true;
}


bool BitcoinExchange::valueIsPositive(const std::string &value) {
    try
    {
        float floatNum = atof(value.c_str());
        return (floatNum >= 0);
    }
    catch(const std::exception& e)
    {
        return (false);
    }
}
bool BitcoinExchange::valueIsNotBig(const std::string &value) {
    try
    {
        float floatNum = atof(value.c_str());
        return (floatNum < 1000);
    }
    catch(const std::exception& e)
    {
        return (false);
    }
}

BitcoinExchange::~BitcoinExchange() {

}

const char* BitcoinExchange::FileNotOpen::what() const throw() {
    return "The File didn't open!";
}
const char* BitcoinExchange::FileIsEmpty::what() const throw() {
    return "File empty or no data!";
}