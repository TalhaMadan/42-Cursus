#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat b1("ta", 1), b2("ma", 2), b3("dan", 148);

	AForm *form1 = intern.makeForm("robotomy request form", "target1");
	AForm *form2 = intern.makeForm("shrubbery creation form", "target2");
	AForm *form3 = intern.makeForm("presidential pardon form", "target3");

	std::cout << b1 << "  |  " << b2 << "  |  " << b3 << std::endl << std::endl;

	std::cout << "-------61-------" << std::endl;
	b1.signForm(*form1);
	b1.executeForm(*form1);
	std::cout << "-------67--------" << std::endl;
	b2.signForm(*form2);
	b2.executeForm(*form2);
	std::cout << "-------34--------" << std::endl;
	b2.signForm(*form3);
	b2.executeForm(*form3);
	std::cout << "creation is over." << std::endl;

	AForm *unknownForm;
	try {
    	unknownForm = intern.makeForm("unknown form", "target");
		b3.signForm(*unknownForm);
		b3.executeForm(*unknownForm);
	}
	catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
	}
	delete form1;
	delete form2;
	delete form3;
	return 0;
}