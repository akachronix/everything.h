#include <iostream>

#include "everything.h"
using namespace libinput;
using namespace libmath;
using namespace libpair;

int main(int argc, const char* argv[])
{
	Pair<double, double> newPair(10.15, 54.21, "newPair");
	newPair.log();

	newPair.set(20.364, 88.534);
	newPair.log();

	std::cin.get();
	return 0;
}