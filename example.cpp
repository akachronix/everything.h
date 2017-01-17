#include <iostream>
#include "everything.h"

using namespace std;

int main(void)
{
	double answer;
	
	math::listOperations();
	
	string operation = io::strinput("What operation to you want to perform?");
	
	if(operation == "add" | operation == "Add")
	{
		double num1 = io::dblinput("Please enter a number.");
		double num2 = io::dblinput("Please enter a numner.");
		answer = math::add(num1, num2);
	}
	
	else if(operation == "subtract" | operation == "Subtract")
	{
		double num1 = io::dblinput("Please enter a number.");
		double num2 = io::dblinput("Please enter a numner.");
		answer = math::sub(num1, num2);
	}
	
	else if(operation == "multiply" | operation == "Multiply")
	{
		double num1 = io::dblinput("Please enter a number.");
		double num2 = io::dblinput("Please enter a numner.");
		answer = math::mul(num1, num2);
	}
	
	else if(operation == "divide" | operation == "Divide")
	{
		double num1 = io::dblinput("Please enter a number.");
		double num2 = io::dblinput("Please enter a numner.");
		answer = math::div(num1, num2);
	}
	
	else if(operation == "squareroot" | operation == "Squareroot" | operation == "squareRoot" | operation == "SquareRoot")
	{
		double num1 = io::dblinput("Please enter a number.");
		answer = math::squareroot(num1);	
	}
	
	else if(operation == "cubicroot" | operation == "Cubicroot" | operation == "cubicRoot" | operation == "CubicRoot")
	{
		double num1 = io::dblinput("Please enter a number.");
		answer = math::cubicroot(num1);
	}
	
	else if (operation == "roundup" | operation == "Roundup" | operation == "roundUp" | operation == "RoundUp")
	{
		double num1 = io::dblinput("Please enter a number.");
		answer = math::roundup(num1);
	}
	
	else if(operation == "rounddown" | operation == "Rounddown" | operation == "roundDown" | operation == "RoundDown")
	{
		double num1 = io::dblinput("Please enter a number.");
		answer = math::rounddown(num1);
	}

	else if(operation == "power" | operation == "Power")
	{
		double num1 = io::dblinput("Please enter a number.");
		double num2 = io::dblinput("Please enter a numner.");
		answer = math::power(num1, num2);
	}
	
	else if(operation == "pi" | operation == "Pi")
	{
		answer = math::pi();
	}
	
	cout << answer << endl;
	
	return 0;
}
