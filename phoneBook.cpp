#include <vector>
#include "phoneBook.h"
#include "linkedList.h"
#include "orderedLinkedList.h"
#include <iterator>
#include <string>
#include <iomanip>

//Creates the default constructor for phoneBook class
phoneBook::phoneBook()
{
	entries = orderedLinkedList<phoneBookEntry>();
}

//Returns the beginning of the vector
phoneBook::iterator phoneBook::begin()
{
	return entries.begin();
}

//Returns the end of the vector
phoneBook::iterator phoneBook::end()
{
	return entries.end();
}

//Insert constructors when parameter is a phoneBook Entry.
void phoneBook::insert(const phoneBookEntry& entry)
{
	if (!find(entry.name()))
	{
		entries.insert(entry);
	}
	else
	{
		entries.erase(entry);
		entries.insert(entry);
	}
}

//Insert constructor when the 3 string parameters are passed
void phoneBook::insert(const std::string& name, const std::string& number, const std::string& email)
{
	phoneBookEntry entry(name, number, email);
	if (!find(name))
	{
		entries.insert(entry);
	}
	else
	{
		entries.erase(entry);
		entries.insert(entry);
	}

}

//Insert constructor when the 2 string parameters are passed
void phoneBook::insert(const std::string& name, const std::string& number)
{
	phoneBookEntry entry(name, number);
	if (!find(name))
	{
		entries.insert(entry);
	}
	else
	{
		entries.erase(entry);
		entries.insert(entry);
	}
}

//Erase constructor
bool phoneBook::erase(std::string name)
{
	phoneBookEntry temp(name, "");
	bool nameHere = false;
	if (find(name))
	{
		entries.erase(temp);
		nameHere = true;
	}

	return nameHere;
}


//Find constructor
bool phoneBook::find(std::string name)
{
	phoneBookEntry entry(name, "");
	return entries.find(entry) != nullptr;
}
	

//Returns index if word is found
/*int phoneBook::findIndex(std::string name)
{
	int index = 0;
	if (find(name))
	{
		for (phoneBookEntryList::iterator it = entries.begin(); it != entries.end(); it++)
		{
			if (it->name().compare(name) == 0)
			{
				return index;
			}
			index++;
		}
	}
	return -1;
}*/

//Prints all the elements in the vector
void phoneBook::print() const
{
			
		std::cout << std::setw(31)<<std::left<<"Name:"<<std::setw(16)<<std::left<<"Phone Number:"<<"E-Mail:"<<std::endl;
		entries.print();
}

//Prints all the elements in the vector using an ostream

void phoneBook::print(std::ostream& out) const
{
	out << std::setw(31) << std::left << "Name:" << std::setw(16) << std::left << "Phone Number:" << "E-Mail:"<<std::endl;
	//for (iterator iter = entries.begin(); iter != entries.end(); iter++)
	//{
		entries.print(out);
	//}
}

//Prints all the variables in the phonebook
void phoneBook::debug(std::ostream& out) const
{
	print(out);
}


//Returns the size of the phoneBook
std::size_t phoneBook::size() const
{
	return entries.size();
}

