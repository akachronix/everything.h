#include <iostream>
#include <utility>
#include <cassert>
#include <cmath>

#include "everything.h"
using namespace libinput;
using namespace libmath;

int main(int argc, const char* argv[])
{
	double distance;
	
	if (argc >= 5)
	{
		std::pair<double, double> first_pair = std::make_pair(atof(argv[1]), atof(argv[2]));
		std::pair<double, double> second_pair = std::make_pair(atof(argv[3]), atof(argv[4]));
		
		distance = Distance(first_pair, second_pair);
	}
	
	else
	{
		std::string x1 = GetString("Enter X1: ");
		std::string y1 = GetString("Enter Y1: ");
		std::cout << std::endl;
		
		std::string x2 = GetString("Enter X2: ");
		std::string y2 = GetString("Enter Y2: ");
		std::cout << std::endl;
		
		distance = Distance(std::make_pair(x1, y1), std::make_pair(x2, y2));
	}
	
	Logger result = Logger(everything, "result.log");
	result << "Distance: ";
	result << distance;
	result << newl;
	
	//std::cout << "Distance: " << distance << std::endl;

	return 0;
}