#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int NumContacts;
	
		static const int MaxCapacity = 8;
		Contact contacts[MaxCapacity];
	public:
		PhoneBook();
		~PhoneBook();
		bool    AddContact(Contact &Contact);
		void    SearchContact();
		void    ContactİsValid(std::string &FirstName, std::string &LastName, std::string &NickName, std::string &PhoneNumber, std::string &DarkestSecret);
		int GetSize();
    	Contact GetContact(int index);
};

#endif