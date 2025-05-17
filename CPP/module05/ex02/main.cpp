#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b1("lemon", 147);
	Bureaucrat b2("banana", 40);
	Bureaucrat b3("orange", 1);

	PresidentialPardonForm f1("foot");
	RobotomyRequestForm f2("hand");
	ShrubberyCreationForm f3("head");

	std::cout << b1 << "  |  " << b2 << "  |  " << b3 << std::endl;
	std::cout << "\n" << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	std::cout << "-------11-------" << std::endl;
	try {
		b1.signForm(f3);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------22-------" << std::endl;
	try {
		f1.execute(b1);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------33-------" << std::endl;
	try {
		f2.execute(b1);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "startinggg..." << std::endl;

	b2.signForm(f3);
	f3.execute(b2);
	std::cout << "-------44-------" << std::endl;
	b3.signForm(f2);
	f2.execute(b3);
	std::cout << "-------55-------" << std::endl;
	b3.signForm(f1);
	f1.execute(b3);

}