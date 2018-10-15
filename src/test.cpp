#include <iostream>
#include <string>
#include <vector>

#include "everything.h"

template <typename _T>
static bool printVector(Logger& logger, std::vector<_T> vector, Logger&(*func)(Logger&))
{
	for (auto& it : vector)
	{
		if (!logger.print(it)) return false;
		if (!logger.print(*func)) return false;
	}
	
	return true;
}

template <typename _T, typename _T2>
static bool printPair(Logger& logger, Pair<_T, _T2> pair, Logger&(*func)(Logger&))
{
	if (!logger.print(pair.first())) return false;
	if (!logger.print(*func)) return false;
	if (!logger.print(pair.second())) return false;
	
	return true;
}

int main(int argc, const char* argv[])
{
	int value1 = GetInt("Enter a first value: ");
	int value2 = GetInt("Enter a second value: ");

	std::cout << '\n';

	Pair<int, int> pair_of_values(value1, value2);

	logger_t console;
	printPair(console, pair_of_values, space);

	std::cin.get();
	return 0;
}