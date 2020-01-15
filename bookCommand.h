#include <iostream>
#include <string>
#include "command.h"
class bookCommand : public command
{
public:
	
	bookCommand(std::istream& inStream, std::ostream& outStream); 

protected:
	std::istream& in;
	std::ostream& out;
	void displayString(std::string& str);
	std::string displayPrompt(std::string& str);



};
#pragma once
