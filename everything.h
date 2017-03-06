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

enum Error
{
	ERROR_NOERROR = 0,
	ERROR_UNEXPECTEDERROR = -1,
	ERROR_TYPEERROR = -2,
	ERROR_ARGERROR = -3,
	ERROR_FILEIOERROR = -4,
	ERROR_OTHERERROR = -5,
};

enum Color
{
	COLOR_BLACK,
	COLOR_WHITE,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_PURPLE,
	COLOR_PINK,
	COLOR_MAGENTA,
	COLOR_YELLOW,
	COLOR_CYAN,
	COLOR_TEAL
};

namespace IO 
{
	signed short int ssIntInput(string question) 
	{
		signed short int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}

	signed int sIntInput(string question) 
	{
		signed int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}

	int IntInput(string question) 
	{
		int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	float FltInput(string question) 
	{
		float userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	double DblInput(string question) 
	{
		double userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	long double lDblInput(string question) 
	{
		long double userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	long LngInput(string question) 
	{
		long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	signed long sLngInput(string question) 
	{
		signed long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	long long LngLngInput(string question) 
	{
		long long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned char uChrInput(string question) 
	{
		unsigned char userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned short int uShtIntInput(string question) 
	{
		unsigned short int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned int uIntInput(string question) 
	{
		unsigned int userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned long uLngInput(string question) 
	{
		unsigned long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
	
	unsigned long long uLngLngInput(string question) 
	{
		unsigned long long userinput;
		cout << question;
		cin >> userinput;
		cout << "\n";
		return userinput;
	}
		
	string StrInput(string question) 
	{
		string userinput;
		cout << question;
		cin >> userinput;
		cout << endl;
		return userinput;
	}
	
	void Delay(double a) 
	{
		usleep(a * 1000);
	}
	
	void ListOperations() 
	{
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

namespace Math 
{
	double Add(double a, double b) 
	{
		return a + b;
	}
	
	double Subtract(double a, double b) 
	{
		return a - b;
	}
	
	double Multiply(double a, double b) 
	{
		return a * b;
	}
	
	double Divide(double a, double b) 
	{
		return a / b;
	}
	
	double SquareRoot(double a) 
	{
		return sqrt(a);
	}
	
	double CubicRoot(double a) 
	{
		return cbrt(a);
	}
	
	double RoundUp(double a) 
	{
		return ceil(a);
	}
	
	double RoundDown(double a) 
	{
		return floor(a);
	}
	
	double Power(double a, double b) 
	{
		return pow(a, b);
	}
	
	double Pi() 
	{
		return atan(1)*4;
	}
}

namespace PtrMath 
{
	void Add(ldbl *ptr, ldbl a, ldbl b) 
	{
		*ptr = a + b;
	}
	
	void Subtract(ldbl *ptr, ldbl a, ldbl b) 
	{
		*ptr = a - b;
	}
	
	void Multiply(ldbl *ptr, ldbl a, ldbl b) 
	{
		*ptr = a * b;
	}
	
	void Divide(ldbl *ptr, ldbl a, ldbl b) 
	{
		*ptr = a / b;
	}
	
	void SquareRoot(ldbl *ptr, ldbl a) 
	{
		*ptr = sqrt(a);
	}
	
	void CubicRoot(ldbl *ptr, ldbl a) 
	{
		*ptr = cbrt(a);
	}
	
	void Power(ldbl *ptr, ldbl base, ldbl exponent) 
	{
		*ptr = pow(base, exponent);
	}
	
	void RoundUp(ldbl *ptr, ldbl a) 
	{
		*ptr = ceil(a);
	}
	
	void RoundDown(ldbl *ptr, ldbl a) 
	{
		*ptr = floor(a);
	}
}

namespace Geometry
{
	namespace Square
	{
		ldbl Area(ldbl a, ldbl b)
		{
			return a * b;
		}
		
		ldbl Perimeter(ldbl a, ldbl b)
		{
			return a + b;
		}
	}
	
	namespace Cube
	{
		ldbl Volume(ldbl a, ldbl b, ldbl c)
		{
			return a * b * c;
		}
	}
}

namespace PtrGeometry
{
	namespace Square
	{
		void Area(ldbl *ptr, ldbl a, ldbl b)
		{
			*ptr = a * b;
		}
		
		void Perimeter(ldbl *ptr, ldbl a, ldbl b)
		{
			*ptr = a + b;
		}
	}
	
	namespace Cube
	{
		void Volume(ldbl *ptr, ldbl a, ldbl b, ldbl c)
		{
			*ptr = a * b * c;
		}
	}
}

namespace RandNum 
{
	void Randomize() 
	{
		srand((unsigned)time(NULL));
	}
	
	int RandInt(int min, int max) 
	{
		return rand() % max + min;
	}
	
	void PtrRandInt(int *ptr, int min, int max)
	{
		*ptr = rand() % max + min;
	}
}

namespace Exception
{
	Error CheckError(Error *errorPtr)
	{
		Error errorCode = *errorPtr;
		
		if(errorCode = ERROR_NOERROR)
			return ERROR_NOERROR;
		else if(errorCode = ERROR_UNEXPECTEDERROR)
			return ERROR_UNEXPECTEDERROR;
		else if(errorCode = ERROR_TYPEERROR)
			return ERROR_TYPEERROR;
		else if(errorCode = ERROR_ARGERROR)
			return ERROR_ARGERROR;
		else if(errorCode = ERROR_FILEIOERROR)
			return ERROR_FILEIOERROR;
		else if(errorCode = ERROR_OTHERERROR)
			return ERROR_OTHERERROR;
		
		*errorPtr = ERROR_NOERROR;
	}
}

#endif
