#include "PhoneBook.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::GetFirstName() const { return FirstName; }

std::string Contact::GetLastName() const { return LastName; }

std::string Contact::GetNickName() const { return NickName; }

std::string Contact::GetPhoneNumber() const { return PhoneNumber; }

std::string Contact::GetDarkestSecret() const { return DarkestSecret; }

Contact::Contact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->NickName = NickName;
	this->PhoneNumber = PhoneNumber;
	this->DarkestSecret = DarkestSecret;
}

void	Contact::display()
{
	std::cout	<<	"First Name : "	<<	FirstName	<<	std::endl
	<<	"Last Name : "	<<	LastName	<<	std::endl
	<<	"Nick Name : "	<<	NickName	<<	std::endl
	<<	"Phone Number : "	<<	PhoneNumber	<<	std::endl
	<<	"Darkest Secret : "	<<	DarkestSecret	<<	std::endl;
}
