#define ERASECOMMAND_H_
#include <iostream>
#include "command.h"
#include "phoneBook.h"
#include "eraseCommand.h"

//Constructor for erase command
eraseCommand::eraseCommand(phoneBook& bookIn, std::istream& inStream, std::ostream& outStream)
	: bookCommand(inStream, outStream), book(bookIn)
{
}

//Erases a input in phoneBook
void eraseCommand::execute() 
{
	std::string personName = "";
	std::string personPrompt = "Enter name to erase";
	personName = displayPrompt(personPrompt);

	if (book.find(personName))
	{
		book.erase(personName);
		out << "Phone book entry " << personName << " was erased" << std::endl;
	}
	else
		out << "Phone book entry " << personName << " was not erased" << std::endl;
}

