#include "bookCommand.h"
#include "phoneBook.h"
class printCommand :public bookCommand
{
public:
	printCommand(phoneBook& bookIn, std::istream& inStream, std::ostream& outStream);
	void execute();

private:
	phoneBook& book;
};
#pragma once

