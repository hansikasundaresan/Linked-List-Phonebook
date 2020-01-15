#include "addUpdateCommand.h"
#include "command.h"
#include "phoneBook.h"

//Creates a constructor in addUpdate Command
addUpdateCommand::addUpdateCommand(phoneBook& bookIn, std::istream& inStream, std::ostream& outStream)
	: bookCommand(inStream, outStream), book(bookIn)
{
}

//Adds the Person to the vector.
void addUpdateCommand::execute() 
{
	std::string personName;
	std::string personPrompt = "Enter name to add/update";
	personName = displayPrompt(personPrompt);
	std::string numberPrompt = "Enter phone number";
	std::string number = displayPrompt(numberPrompt);
	std::string emailPrompt = "Enter e-mail address";
	std::string email = displayPrompt(emailPrompt);

	//Message to deliver when added
	if (book.find(personName))
	{
		std::cout << "Updating phone book entry for " << personName << std::endl;
	}
	else
	{
		std::cout << "Adding phone book entry for " << personName << std::endl;
	}
	book.insert(personName, number, email);
}

