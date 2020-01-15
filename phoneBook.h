#include <vector>
#include "phoneBookEntry.h"
#include "linkedList.h"
#include "orderedLinkedList.h"
#include <iostream>
class phoneBook 
{
public:
	phoneBook();
	typedef orderedLinkedList<phoneBookEntry> phoneBookEntryList;
	typedef phoneBookEntryList::iterator iterator;
	typedef phoneBookEntryList::const_iterator const_iterator;
	void insert(const phoneBookEntry& entry);
	void insert(const std::string& name, const std::string& number, const std::string& email);
	void insert(const std::string& name, const std::string& number);
	bool erase(std::string name);
	bool find(std::string name);
	int findIndex(std::string name);
	void print() const;
	void print(std::ostream& out) const;
	void debug(std::ostream& out) const;
	std::size_t size() const;
	iterator begin();
	iterator end();
private:
	phoneBookEntryList entries;
};
#pragma once
