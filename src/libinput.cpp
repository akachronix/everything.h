#include "libinput.hpp"

#include <iostream>
#include <string>

int GetInt(std::string prompt)
{
	int input = 0;
	std::cout << prompt;
	std::cin >> input;
	return input;
}

long int GetLongInt(std::string prompt)
{
	long int input = 0;
	std::cout << prompt;
	std::cin >> input;
	return input;
}

long long int GetLongLongInt(std::string prompt)
{
	long long int input = 0;
	std::cout << prompt;
	std::cin >> input;
	return input;
}

float GetFloat(std::string prompt)
{
	float input = 0;
	std::cout << prompt;
	std::cin >> input;
	return input;
}

double GetDouble(std::string prompt)
{
	double input = 0;
	std::cout << prompt;
	std::cin >> input;
	return input;
}

long double GetLongDouble(std::string prompt)
{
	long double input = 0;
	std::cout << prompt;
	std::cin >> input;
	return input;
}

std::string GetString(std::string prompt)
{
	std::string input = "";
	std::cout << prompt;
	std::cin >> input;
	return input;
}