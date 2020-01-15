#include <iostream>
#include "command.h"
#include "phoneBook.h"
#include "printCommand.h"

//Constructor for the print command
printCommand::printCommand(phoneBook& bookIn, std::istream& inStream, std::ostream& outStream)
	: bookCommand(inStream, outStream), book(bookIn)
{
}

//Prints out all values in the phoneBook
void printCommand::execute()
{
	book.print(out);
} 
