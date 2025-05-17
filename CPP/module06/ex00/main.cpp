#include "ScalarConverter.hpp"

int main (int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Wrong Argument!" << std::endl;
		return 1;
	}
	std::string argv = av[1];
	ScalarConverter::convert(argv);
	return 0;
}
