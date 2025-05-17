#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

static AForm *makePresidentialPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

static AForm *makeRobotomyRequest(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *makeShrubberyCreation(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    static const std::string forms[] = {"presidential pardon form", "robotomy request form", "shrubbery creation form"};
    static AForm* (*formCreators[])(const std::string&) = {makePresidentialPardon, makeRobotomyRequest, makeShrubberyCreation};

    for (int i = 0; i < 3; ++i) {
        if (name == forms[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return formCreators[i](target);
        }
    }
    throw Intern::UnknownFormExeption();
}

const char *Intern::UnknownFormExeption::what() const throw()
{
	return "Invalid form type!";
}