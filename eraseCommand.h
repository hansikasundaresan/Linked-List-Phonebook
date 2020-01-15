#define ERASECOMMAND_H_
#include "bookCommand.h"
#include "phoneBook.h"
class eraseCommand :public bookCommand
{
public:
	// any other code you may need
	eraseCommand(phoneBook& bookIn, std::istream& inStream, std::ostream& outStream);
	void execute();

private:
	phoneBook& book;
};
#pragma once
