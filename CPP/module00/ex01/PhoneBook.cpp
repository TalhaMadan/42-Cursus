#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : NumContacts(0) {}

PhoneBook::~PhoneBook() {}

bool	PhoneBook::AddContact(Contact &Contact)
{
	if	(NumContacts < MaxCapacity)
	{
		contacts[NumContacts] = Contact;
		NumContacts += 1;
		return true;
	}
	else
	{
		for (int i = 0; i < MaxCapacity - 1; i++)
		{
			contacts[i] = contacts[i + 1];
		}
		contacts[MaxCapacity - 1] = Contact;
		return true;
	}
	return false;
}

void PhoneBook::SearchContact()
{
    std::cout << std::setw(15) << "Index"
              << "|"
              << std::setw(15) << "First Name"
              << "|"
              << std::setw(15) << "Last Name"
              << "|"
              << std::setw(15) << "Nick Name"
              << "|" << std::endl;
    std::cout << std::setfill('-') << std::setw(65) << "-" << std::endl;
    std::cout << std::setfill(' ');

    for (int i = 0; i < NumContacts; i++)
	{
		std::cout << std::setw(15) << i << "|" << std::setw(15)
			<< contacts[i].GetFirstName().substr(0, 9) + (contacts[i].GetFirstName().length() > 9 ? "." : "") << "|"
			<< std::setw(15) << contacts[i].GetLastName().substr(0, 9) + (contacts[i].GetLastName().length() > 9 ? "." : "") << "|"
			<< std::setw(15) << contacts[i].GetNickName().substr(0, 9) + (contacts[i].GetNickName().length() > 9 ? "." : "") << "|" << std::endl;
	}


    if (NumContacts == 0)
    {
        std::cout << "The phone book is empty." << std::endl;
    }
}

int PhoneBook::GetSize()
{
    return NumContacts;
}

Contact PhoneBook::GetContact(int index)
{
    return contacts[index];
}

std::string	input_collector(std::string prompt)
{
	std::string input;
	do
	{
		std::cout << prompt;
		std::getline(std::cin, input);
	} while(input.empty());

	return input;
}

void	PhoneBook::ContactİsValid(std::string &FirstName, std::string &LastName, std::string &NickName, std::string &PhoneNumber, std::string &DarkestSecret)
{
	FirstName = input_collector("First Name			:     ");
	LastName = input_collector("Last Name				:     ");
	NickName = input_collector("Nick Name				:     ");
	PhoneNumber = input_collector("Phone Number			:     ");
	DarkestSecret = input_collector("Darkest Secret		:     ");
}