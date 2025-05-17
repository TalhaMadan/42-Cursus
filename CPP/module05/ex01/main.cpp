#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	b1("b1", 1);
	Bureaucrat	b2("b2", 120);
	Bureaucrat	b3("b3", 20);
	Form 		f1("f1", 2, 2);
	Form 		f2("f2", 100, 100);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;

	std::cout << f2 << std::endl;

	try {
		b1.incrementGrade();
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << f1 << std::endl;
	
	try {
		f2.beSigned(b2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		f1.beSigned(b1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		f2.beSigned(b3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		f2.beSigned(b1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
