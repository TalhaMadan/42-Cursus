#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public:
		Contact();
		~Contact();
		
		std::string GetFirstName() const;
    	std::string GetLastName() const;
    	std::string GetNickName() const;
    	std::string GetPhoneNumber() const;
    	std::string GetDarkestSecret() const;
	
		Contact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret);
		void    display();
	
};

#endif