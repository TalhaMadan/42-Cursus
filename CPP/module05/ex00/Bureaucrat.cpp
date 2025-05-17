#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("uncompleted"){
	this->grade = 150;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name) {
	std::cout << "Bureaucrat assigment operator called" << std::endl;
	if(this != &copy)
		*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	std::cout << "Bureaucrat assigment operator called" << std::endl;
	this->grade = copy.grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name){
	if (grade <	1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

const std::string &Bureaucrat::getName() const{
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream &bN, const Bureaucrat &gN) {
	bN << gN.getName() << 	", bureaucrat grade " << gN.getGrade();
	return bN;
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Bureaucrat grade too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "Bureaucrat grade too high!";
}