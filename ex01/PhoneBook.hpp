#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;
	int oldestContactIndex;

public:
	PhoneBook();
	~PhoneBook();
	
	void addContact(const Contact& contact);
	void searchContacts() const;
	void displayContactList() const;
	void displayContactByIndex(int index) const;
	int getContactCount() const;
};

#endif 