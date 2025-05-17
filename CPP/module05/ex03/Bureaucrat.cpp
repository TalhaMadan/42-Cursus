#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("undifined"){
	this->grade = 150;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name){
	if (this != &copy)
		*this = copy ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy){
	this->grade = copy.grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
	}

}

void Bureaucrat::executeForm(AForm const &form)
{
	try{
		std::cout << this->name << " trying to execute " << ((AForm&)form).getName() << std::endl;
		((AForm&)form).execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " could not execute " << ((AForm&)form).getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "The entered grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "The entered grade is too low.";
}

std::ostream &operator<<(std::ostream &bN, const Bureaucrat &gN) {
	bN << gN.getName() << ", bureaucrat grade " << gN.getGrade();
	return bN;
}