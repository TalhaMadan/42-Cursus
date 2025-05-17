#include "Harl.hpp"


int main(int argc, char **argv)
{
	std::string level;
	Harl harl;

	if(argc != 2)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return (1);
	}

	level = argv[1];
	harl.complain(level);

}