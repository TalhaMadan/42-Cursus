#include "ScalarConverter.hpp"

bool ScalarConverter::isSingleCharacter(std::string var)
{
    return var.length() == 1 && !isdigit(var[0]);
}

void ScalarConverter::to_char(std::string var)
{
    if (isSingleCharacter(var)) {
        std::cout << "char: '" << var[0] << "'" << std::endl;
    }
    else {
        try {
            int i = std::atoi(var.c_str());
            if (i < 32 || i > 126)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: " << "'" << (char)i << "'" << std::endl;
        }
        catch (...) {
            std::cout << "An error occurred while casting to char." << std::endl;
        }
    }
}



void ScalarConverter::to_int(std::string var)
{
    if (isSingleCharacter(var)) {
        int av = static_cast<int>(var[0]);
        std::cout << "int: " << av << std::endl;
    }
    else {
            // Stringstream ile integer dönüşümü
            std::stringstream ss(var);
            int i;
            ss >> i;
            if (ss.fail()) {
                std::cout << "An error occurred while casting to int." << std::endl;
            } else {
                std::cout << "int: " << i << std::endl;
            }
    }
}

void ScalarConverter::to_float(std::string var)
{
    float f;
    if (isSingleCharacter(var)) {
        float av = static_cast<float>(var[0]);
        std::cout << "float: " << av << ".0f" << std::endl;
    }
    else {
        try {
            f = std::atof(var.c_str());
            std::cout << "float: " << f;
            if (f == static_cast<int>(f))
                std::cout << ".0f";
            else if (__INT_MAX__ > f) {
                std::cout << "f";
            }
            else 
                std::cout << ".f";
            std::cout << std::endl;
        }
        catch (...) {
            std::cout << "An error occurred while casting to float." << std::endl;
        }
    }
}

void ScalarConverter::to_double(std::string var)
{
    if (isSingleCharacter(var)) {
        double av = static_cast<double>(var[0]);
        std::cout << "double: " << av << ".0" << std::endl;
    }
    else {
        try {
            double d = std::atof(var.c_str());
            std::cout << "double: " << d;
            if (d == static_cast<int>(d))
                std::cout << ".0";
            std::cout << std::endl;
        }
        catch (...) {
            std::cout << "An error occurred while casting to double." << std::endl;
        }
    }
}

int ScalarConverter::pseudo_check(std::string var)
{
    std::string input_p[] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};
    std::string pl;
    int i = 0;
    while (i < 6)
    {
        if (input_p[i] == var) {
            pl = input_p[i % 3];
            break;
        }
        i++;
    }
    if (i == 6)
        return (0);
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << pl << "f" << std::endl;
    std::cout << "double: " << pl << std::endl;
    return (1);
}

void ScalarConverter::convert(std::string var)
{
    if (pseudo_check(var))
        return;
    to_char(var);
    to_int(var);
    to_float(var);
    to_double(var);
}