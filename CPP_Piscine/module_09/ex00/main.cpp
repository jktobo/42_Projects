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