#include "command.h"
#include <iostream>
#include "bookCommand.h"

//Constructor for bookCommand
bookCommand::bookCommand(std::istream& inStream, std::ostream
	& outStream)
	: in(inStream), out(outStream)
{
	
}

//Display the message string
void bookCommand::displayString(std::string& str)
{
	out << str<<std::endl;
}

//Display a message for the user to input something 
std::string bookCommand::displayPrompt(std::string& str)
{
	std::string input;
	out << str<<std::endl;
	getline(in, input);
	return input;
}