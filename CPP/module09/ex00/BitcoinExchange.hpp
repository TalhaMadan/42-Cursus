#ifndef BITCOIN_EXCHANGE
# define BITCOIN_EXCHANGE

#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <exception>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <fstream>


class BitcoinExchange {
    private:
        std::map <std::string, float> data;
        std::string path;
        void fillData();
        void checkBalance();
        float checkDate(std::string date);
        std::map<std::string, float>::iterator findNearestDate(int year, int month, int day);

        float toFloat(const std::string& str);
        int toInt(const std::string& str);
    public:
        BitcoinExchange();
        BitcoinExchange(std::string pathcsv);
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        ~BitcoinExchange();

        void func();

        std::string getPath() const;
};

#endif