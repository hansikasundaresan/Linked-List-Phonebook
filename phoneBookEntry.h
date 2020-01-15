#include <iostream>
class phoneBookEntry {
public:
	phoneBookEntry();
	phoneBookEntry(const std::string& name, const std::string& number);
	phoneBookEntry(const std::string& name, const std::string& number, const std::string& email);
	phoneBookEntry(const phoneBookEntry& from);
	std::string name() const;
	std::string phoneNumber() const;
	std::string email() const;

	void phoneNumber(const std::string& newNumber);
	void email(const std::string& newEmail);
	bool operator==(const phoneBookEntry& entry) const;
	bool operator!=(const phoneBookEntry& entry) const;
	bool operator<(const phoneBookEntry& entry) const;
	bool operator<=(const phoneBookEntry& entry) const;
	bool operator>(const phoneBookEntry& entry) const;
	bool operator>=(const phoneBookEntry& entry) const;

private:
	std::string nameEntry;
	std::string phoneNumberEntry;
	std::string emailEntry;

};

std::ostream& operator<<(std::ostream& out, const phoneBookEntry& entry);

#pragma once
