#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>

class ScalarConverter {
	private:
		static void to_char(std::string var);
		static void to_int(std::string var);
		static void to_float(std::string var);
		static void to_double(std::string var);

		static bool isSingleCharacter(std::string var);
		static int pseudo_check(std::string var);
	public:
		static void convert(std::string var);
};

#endif