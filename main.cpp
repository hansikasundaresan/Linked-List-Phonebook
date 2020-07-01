#include <iostream>
#include <string>
#include "linkedList.h"
#include "orderedLinkedList.h"
#include "phoneBookEntry.h"
#include "phoneBook.h"
#include "menuList.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"
#include "bookCommand.h"
int main()
{
    menuList variableML("Phone book menu:");
    phoneBook variablePB;
    std::ostream outStream(nullptr);
    std::istream inStream(nullptr);
    addUpdateCommand addUpVar(variablePB, std::cin, std::cout);
    eraseCommand eraseVar(variablePB, std::cin, std::cout);
    printCommand printVar(variablePB, std::cin, std::cout);
    menuItem item('a', "add/update", addUpVar);
    menuItem item2('e', "erase", eraseVar);
    menuItem item3('p', "print", printVar);
    variableML.add(item);
    variableML.add(item2);
    variableML.add(item3);
    std::cout << "Starting the Phone Book" << std::endl << std::endl;
    variableML.start();
    return 0;
}
