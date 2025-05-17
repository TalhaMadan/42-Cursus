#include "PhoneBook.hpp"

int	IsAllDigit(std::string str)
{
	int i = str.length();
	
	if (i == 0)
		return 0;
	
	while (--i != -1)
		if (!(std::isdigit(str[i])))
		{
			std::cout << "The index must be digit!!" << std::endl;
			return 0;
		}
	return 1;
}

int GetIndexNumber()
{
	std::string index;

	do
	{
		std::getline(std::cin, index);
	} while (!IsAllDigit(index));

	return std::atoi(index.c_str());
}

int main()
{
	PhoneBook	phonebook;
	std::string	command;
	std::string	FirstPrompt = "         ---ADD--- 		|	give \"ADD\" input for add new contact. \n \
	---SEARCH--- 	|	give \"SEARCH\" input for search contacts. \n \
	---EXIT--- 	|	give \"EXIT\" input for exit program. \n\n \
	What you want ?";
	
	std::cout	<< "Welcome to Phone Book ! \n\n"	<< std::endl
	<<	FirstPrompt <<	std::endl;
	
	while(std::getline(std::cin, command))
	{
		int	falsectrl = 0;
		if (command == "ADD")
		{
			std::string	FirstName, LastName, NickName, PhonNumber, DarkestSecret;

			phonebook.ContactİsValid(FirstName, LastName, NickName, PhonNumber, DarkestSecret);
			Contact	Contact(FirstName, LastName, NickName, PhonNumber, DarkestSecret);
			phonebook.AddContact(Contact);
			std::cout << "Contact : \"" << FirstName << "\" added phone book." << std::endl;
		}
		else if (command == "SEARCH")
		{
			phonebook.SearchContact();
			std::cout	<<	"Enter contact index for view : ";
			int	index = GetIndexNumber();
			
			if (index < 0 || index >= phonebook.GetSize())
            {
                std::cout << "Invalid index.\n";
            }
            else
            {
                phonebook.GetContact(index).display();
            }
		}
		else if (command == "EXIT")
		{
			std::cout << "Program stopping. Goodbye :)" << std::endl;
			return (0);
		}
		else
		{
			std::cout << "Please insert valid input." << std::endl
			<< FirstPrompt << std::endl;
			falsectrl = 1;
		}
		if (falsectrl != 1)
			std::cout << "------------------- \n You are still in the phone book. \n\n" << FirstPrompt << std::endl;
	}
	return (0);
}