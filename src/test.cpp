#include <iostream>
#include <utility>
#include <cassert>
#include <cmath>

#include "everything.h"
using namespace libinput;
using namespace libmath;

int main(int argc, const char* argv[])
{
	short value1 = 1;
	unsigned short value2 = 2;
	int value3 = 3;
	unsigned int value4 = 4;
	float value5 = 5.5;
	double value6 = 6.5;
	long double value7 = 7.5;
	const char* value8 = "This is a const char*";
	std::string value9 = "This is a std::string";
	
	Logger terminal(everything, "biggay.log");
	
	terminal << value1;
	terminal << newl;
	
	terminal << value2;
	terminal << newl;
	
	terminal << value3;
	terminal << newl;
	
	terminal << value4;
	terminal << newl;
	
	terminal << value5;
	terminal << newl;
	
	terminal << value6;
	terminal << newl;
	
	terminal << value7;
	terminal << newl;
	
	terminal << value8;
	terminal << newl;
	
	terminal << value9;
	terminal << newl;
	
	std::cin.get();
	return 0;
}