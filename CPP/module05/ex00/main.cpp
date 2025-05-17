#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;
	std::cout << a << std::endl;
	Bureaucrat b1("cherry", 100);
	std::cout << b1 << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	try
	{
		Bureaucrat b("b", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
		try
	{
		Bureaucrat a1("b", 150);
		std::cout << a1 << std::endl;
		a1.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
