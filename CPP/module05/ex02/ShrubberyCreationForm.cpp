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
		throw AForm::GradeTooHighException();
	else
		this->isSigned = true;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooHighException();
	else
	{
		// Dosya adı olarak std::string'i .c_str() ile const char*'a dönüştürüyoruz
		std::ofstream file((this->target + "_shrubbery").c_str(), std::ios::trunc);
		
		if (!file.is_open()) {
			std::cout << "Error: Failed to open the file for writing." << std::endl;
			throw std::runtime_error("Failed to open the file!");
		}

		// Shrubbery ASCII sanatını dosyaya yazıyoruz
		file << 
        "                oxoxoo    ooxoo                          \n"
		"               ooxoxo oo  oxoxooo                        \n"
		"              oooo xxoxoo ooo ooox                       \n"
		"              oxo o oxoxo  xoxxoxo                       \n"
		"               oxo xooxoooo o ooo                        \n"
		"                 ooooo  /o/o                           \n"
		"                     \\ \\/ /                             \n"
		"                      |   /                              \n"
		"                      | D|                               \n"
		"                      |  |                               \n"
		"                      |  |                               \n"
		"               ______/__ \\____                          \n"
		" -----------------------------------------------------   \n" << std::endl;

		// Dosyayı kapatıyoruz
		file.close();
		std::cout << this->target + "_shrubbery created" << std::endl;
	}

}

