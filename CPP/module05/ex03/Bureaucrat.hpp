#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		Bureaucrat(const std::string &name, int grade);

		const std::string &getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		class GradeTooHighException :public std::exception{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException :public std::exception{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &bN, const Bureaucrat &gN);

#endif