#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
	if(this != &copy)
		*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	AForm::operator=(copy);
	this->target = copy.target;
	return *this;
}

void ShrubberyCreationForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->isSigned == true)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
    if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
    else
    {
        // Dosya ismini c_str() ile const char*'e dönüştürün
        std::ofstream file((this->target + "_shrubbery").c_str(), std::ios::trunc);

        if (!file.is_open())
        {
            std::cout << "Error: Failed to open the file for writing." << std::endl;
            throw std::runtime_error("Failed to open the file!");
        }

        file << 
        "                        @@@@@                            \n"
		"               ,,     ,@@@@@@@,      8888o               \n"
		"              ,,,.   ,@@@@@@/@@,  .oo8888oo.             \n"
		"           ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o            \n"
		"          ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'         \n"
		"           %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'         \n"
		"          %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'           \n"
		"          `&%\\ ` /%&'    |.|        \\ '|8'             \n"
		"              |o|        | |         | |                 \n"
		"              |.|        | |         | |                 \n"
		"        jgs \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_   \n"
		" -----------------------------------------------------   \n" << std::endl;

        file.close();
        std::cout << this->target + "_shrubbery created" << std::endl;
    }
}