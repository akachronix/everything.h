#include <iostream>
#include <string>

#include "everything.h"
using namespace libinput;

int main(int argc, const char* argv[])
{
	std::string userinput = GetString("Say something: ");
	std::cout << userinput << std::endl;

	std::cin.get();
	return 0;
}
