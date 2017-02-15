/* Name:        everything.h
   Author:      Brendan Gowen 
   Description: A header file that
   includes everything I might need
   for developing an application. */

#ifndef EVERYTHING_H
#define EVERYTHING_H  

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::cin;

typedef long double ldbl;

namespace io {
	signed short int ssintinput(string question) {
		signed short int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}

	signed int sintinput(string question) {
		signed int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}

	int intinput(string question) {
		int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	float fltinput(string question) {
		float userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	double dblinput(string question) {
		double userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	long double ldblinput(string question) {
		long double userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	long lnginput(string question) {
		long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	signed long slnginput(string question) {
		signed long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	long long lnglnginput(string question) {
		long long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned char uchrinput(string question) {
		unsigned char userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned short int ushtintinput(string question) {
		unsigned short int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned int uintinput(string question) {
		unsigned int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned long ulnginput(string question) {
		unsigned long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned long long ulnglnginput(string question) {
		unsigned long long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
		
	string strinput(string question) {
		string userinput;
		cout << question;
		cin >> userinput;
		cout << endl;
		return userinput;
	}
	
	void delay(double a) {
		usleep(a * 1000);
	}
}

namespace math {
	double add(double a, double b) {
		return a + b;
	}
	
	double subtract(double a, double b) {
		return a - b;
	}
	
	double multiply(double a, double b) {
		return a * b;
	}
	
	double divide(double a, double b) {
		return a / b;
	}
	
	double squareroot(double a) {
		return sqrt(a);
	}
	
	double cubicroot(double a) {
		return cbrt(a);
	}
	
	double roundup(double a) {
		return ceil(a);
	}
	
	double rounddown(double a) {
		return floor(a);
	}
	
	double power(double a, double b) {
		return pow(a, b);
	}
	
	double pi() {
		return atan(1)*4;
	}
	
	void listOperations() {
		cout << "Add" << endl;
		cout << "Subtract" << endl;
		cout << "Multiply" << endl;
		cout << "Divide" << endl;
		cout << "SquareRoot" << endl;
		cout << "CubicRoot" << endl;
		cout << "RoundUp" << endl;
		cout << "RoundDown" << endl;
		cout << "Power" << endl;
		cout << "Pi" << endl;
		cout << endl;
	}
}

namespace ptrMath {
	void add(ldbl *ptr, ldbl a, ldbl b) {
		ldbl ptrAnswer = a + b;
		*ptr = ptrAnswer;
	}
	
	void subtract(ldbl *ptr, ldbl a, ldbl b) {
		ldbl ptrAnswer = a - b;
		*ptr = ptrAnswer;
	}
	
	void multiply(ldbl *ptr, ldbl a, ldbl b) {
		ldbl ptrAnswer = a * b;
		*ptr = ptrAnswer;
	}
	
	void divide(ldbl *ptr, ldbl a, ldbl b) {
		ldbl ptrAnswer = a / b;
		*ptr = ptrAnswer;
	}
	
	void squareroot(ldbl *ptr, ldbl a) {
		ldbl ptrAnswer = sqrt(a);
		*ptr = ptrAnswer;
	}
	
	void cubicroot(ldbl *ptr, ldbl a) {
		ldbl ptrAnswer = cbrt(a);
		*ptr = ptrAnswer;
	}
	
	void power(ldbl *ptr, ldbl base, ldbl exponent) {
		ldbl ptrAnswer = pow(base, exponent);
		*ptr = ptrAnswer;
	}
	
	void roundup(ldbl *ptr, ldbl a) {
		ldbl ptrAnswer = ceil(a);
		*ptr = ptrAnswer;
	}
	
	void rounddown(ldbl *ptr, ldbl a) {
		ldbl ptrAnswer = floor(a);
		*ptr = ptrAnswer;
	}
}

namespace randnum {
	void randomize() {
		srand((unsigned)time(NULL));
	}
	
	int randint(int min, int max) {
		return rand() % max + min;
	}
}

#endif
