#include "phoneBookEntry.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>

//Constructors for phoneBookEntry
phoneBookEntry::phoneBookEntry()
{
	nameEntry = "";
	emailEntry = "";
	phoneNumberEntry = "";
}

phoneBookEntry::phoneBookEntry(const std::string& name, const std::string& number)
{
	nameEntry = name;
	phoneNumberEntry = number;
	emailEntry = "";
}

phoneBookEntry::phoneBookEntry(const std::string& name, const std::string& number, const std::string& email)
{
	nameEntry = name;
	phoneNumberEntry = number;
	emailEntry = email;
}

phoneBookEntry::phoneBookEntry(const phoneBookEntry& from)
{
	nameEntry = from.name();
	emailEntry = from.email();
	phoneNumberEntry = from.phoneNumber();
}

//Returns the name in the phoneBookEntry
std::string phoneBookEntry::name() const
{
	return nameEntry;
}

//Returns the number in the phoneBookEntry
std::string phoneBookEntry::phoneNumber() const
{
	return phoneNumberEntry;
}

//Returns the email in the phoneBookEntry
std::string phoneBookEntry::email() const
{
	return emailEntry;
}

//Sets the number in the phoneBookEntry
void phoneBookEntry::phoneNumber(const std::string& newNumber)
{
	phoneNumberEntry = newNumber;
}

//Sets the email in the phoneBookEntry
void phoneBookEntry::email(const std::string& newEmail)
{
	emailEntry = newEmail;
}

bool phoneBookEntry:: operator==(const phoneBookEntry& entry) const
{
	return (nameEntry.compare(entry.name()) == 0);
}
bool phoneBookEntry:: operator!=(const phoneBookEntry& entry) const
{
	return !(nameEntry.compare(entry.name()) == 0);
}
bool phoneBookEntry:: operator<(const phoneBookEntry& entry) const
{
	return (nameEntry.compare(entry.name()) < 0);
}
bool phoneBookEntry:: operator<=(const phoneBookEntry& entry) const
{
	return (nameEntry.compare(entry.name()) <= 0);
}
bool phoneBookEntry:: operator>(const phoneBookEntry& entry) const
{
	return (nameEntry.compare(entry.name()) > 0);
}
bool phoneBookEntry::operator>=(const phoneBookEntry& entry) const
{
	return (nameEntry.compare(entry.name()) >= 0);
}

std::ostream& operator<<(std::ostream& out, const phoneBookEntry& entry)
{
	if (entry.email().compare("") == 0)
	{
		if (entry.phoneNumber().compare("") == 0)
		{
			if (entry.name().compare("") == 0)
			{
				//out 
				return out;
			}

		}
	

		out << std::setw(31) << std::left << entry.name() << std::setw(16) << std::left << entry.phoneNumber() <<  std::endl;
		return out;
	}
	out << std::setw(31) << std::left << entry.name() << std::setw(16) << std::left << entry.phoneNumber() << entry.email() << std::endl;
	return out;
}

