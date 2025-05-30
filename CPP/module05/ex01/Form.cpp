#include "Form.hpp"

Form::Form() : name("Default Form"), gradeToSign(150), gradeToExecute(150)
{
	this->isSigned = false;
}

Form::~Form(){
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->isSigned = false;
}

Form::Form(const Form &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
	if (this != &copy)
		*this = copy;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "Just sign copied, other things const they can't overwritten." << std::endl;
	this->isSigned = copy.isSigned;
	return *this;
}

const std::string &Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign || bureaucrat.getGrade() > this->gradeToExecute)
		throw Form::GradeTooHighException();
	if (this->isSigned == false)
	{
		this->isSigned = true;
		std::cout << this->name + " has been signed by " << bureaucrat.getName() << std::endl;
	}
	else
		std::cout << this->name + " is already signed." << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form: grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form: grade is too low.";
}

std::ostream &operator<<(std::ostream &bN, const Form &e) {
	bN << "Form " << e.getName() << " is " << (e.getIsSigned() ? "" : "not ") 
		<< "signed. Grade to sign is: " << e.getGradeToSign() 
		<< ". Grade to execute is: " << e.getGradeToExecute();
	return bN;
}
