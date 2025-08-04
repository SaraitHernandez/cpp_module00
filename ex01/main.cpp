#include "PhoneBook.hpp"
#include <iostream>
#include <string>

std::string getInput(const std::string& prompt) {
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}

Contact createContact() {
	Contact contact;
	
	contact.setFirstName(getInput("Enter first name: "));
	contact.setLastName(getInput("Enter last name: "));
	contact.setNickname(getInput("Enter nickname: "));
	contact.setPhoneNumber(getInput("Enter phone number: "));
	contact.setDarkestSecret(getInput("Enter darkest secret: "));
	
	return contact;
}

int main() {
	PhoneBook phonebook;
	std::string command;
	
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	
	while (true) {
		command = getInput("Enter command: ");
		
		if (command == "ADD") {
			Contact newContact = createContact();
			phonebook.addContact(newContact);
			std::cout << "Contact added successfully!" << std::endl;
		}
		else if (command == "SEARCH") {
			phonebook.searchContacts();
		}
		else if (command == "EXIT") {
			std::cout << "Goodbye! Contacts will be lost forever!" << std::endl;
			break;
		}
		else {
			std::cout << "Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
		}
	}
	
	return 0;
} 