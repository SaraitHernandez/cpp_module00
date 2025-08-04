#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

PhoneBook::PhoneBook() {
	contactCount = 0;
	oldestContactIndex = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact(const Contact& contact) {
	if (contactCount < 8) {
		contacts[contactCount] = contact;
		contactCount++;
	} else {
		contacts[oldestContactIndex] = contact;
		oldestContactIndex = (oldestContactIndex + 1) % 8;
	}
}

void PhoneBook::searchContacts() const {
	if (contactCount == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	
	displayContactList();
	
	std::cout << "Enter the index of the contact to display: ";
	int index;
	std::cin >> index;
	
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input!" << std::endl;
		return;
	}
	
	if (index >= 0 && index < contactCount) {
		displayContactByIndex(index);
	} else {
		std::cout << "Index out of range!" << std::endl;
	}
}

void PhoneBook::displayContactList() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	
	for (int i = 0; i < contactCount; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contacts[i].truncateField(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << contacts[i].truncateField(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << contacts[i].truncateField(contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContactByIndex(int index) const {
	if (index >= 0 && index < contactCount) {
		contacts[index].displayContact();
	}
}

int PhoneBook::getContactCount() const {
	return contactCount;
} 