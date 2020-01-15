#include "bookCommand.h"
#include "phoneBook.h"
class addUpdateCommand :public bookCommand
{
public:
	// any other code you may need
	addUpdateCommand(phoneBook& bookIn, std::istream& inStream, std::ostream& outStream);
	void execute();
	 
private:
	phoneBook& book;
};
#pragma once
