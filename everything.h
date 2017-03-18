/* Name:        everything.h
 * Author:      Brendan Gowen
 * Description: A header file that
 * includes everything I might need
 * for developing an application.
 *
 * License:
 * everything.h, a header file that includes everything I might need for developing an application.
 * Copyright (C) 2017 Brendan Gowen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EVERYTHING_H
#define EVERYTHING_H

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <cmath>

typedef std::vector<std::string>    string_vect;
typedef std::vector<double>         double_vect;
typedef std::vector<float>          float_vect;
typedef std::vector<char>           char_vect;
typedef std::vector<int>            int_vect;

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
	signed short int ssIntInput(std::string question)
	{
		signed short int userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	signed int sIntInput(std::string question)
	{
		signed int userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	int IntInput(std::string question)
	{
		int userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	float FltInput(std::string question)
	{
		float userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	double DblInput(std::string question)
	{
		double userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	long double lDblInput(std::string question)
	{
		long double userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	long LngInput(std::string question)
	{
		long userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	signed long sLngInput(std::string question)
	{
		signed long userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	long long LngLngInput(std::string question)
	{
		long long userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	unsigned char uChrInput(std::string question)
	{
		unsigned char userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	unsigned short int uShtIntInput(std::string question)
	{
		unsigned short int userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	unsigned int uIntInput(std::string question)
	{
		unsigned int userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	unsigned long uLngInput(std::string question)
	{
		unsigned long userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	unsigned long long uLngLngInput(std::string question)
	{
		unsigned long long userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	std::string StrInput(std::string question)
	{
		std::string userinput;
		std::cout << question;
		std::cin >> userinput;
		std::cout << std::endl;
		return userinput;
	}

	void Delay(double a)
	{
		usleep(a * 1000);
	}

	void ListOperations()
	{
		std::cout << "Add" << std::endl;
		std::cout << "Subtract" << std::endl;
		std::cout << "Multiply" << std::endl;
		std::cout << "Divide" << std::endl;
		std::cout << "SquareRoot" << std::endl;
		std::cout << "CubicRoot" << std::endl;
		std::cout << "RoundUp" << std::endl;
		std::cout << "RoundDown" << std::endl;
		std::cout << "Power" << std::endl;
		std::cout << "Pi" << std::endl;
		std::cout << std::endl;
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
	void Add(long double *ptr, long double a, long double b)
	{
		*ptr = a + b;
	}

	void Subtract(long double *ptr, long double a, long double b)
	{
		*ptr = a - b;
	}

	void Multiply(long double *ptr, long double a, long double b)
	{
		*ptr = a * b;
	}

	void Divide(long double *ptr, long double a, long double b)
	{
		*ptr = a / b;
	}

	void SquareRoot(long double *ptr, long double a)
	{
		*ptr = sqrt(a);
	}

	void CubicRoot(long double *ptr, long double a)
	{
		*ptr = cbrt(a);
	}

	void Power(long double *ptr, long double base, long double exponent)
	{
		*ptr = pow(base, exponent);
	}

	void RoundUp(long double *ptr, long double a)
	{
		*ptr = ceil(a);
	}

	void RoundDown(long double *ptr, long double a)
	{
		*ptr = floor(a);
	}
}

namespace Geometry
{
	namespace Square
	{
		long double Area(long double a, long double b)
		{
			return a * b;
		}

		long double Perimeter(long double a, long double b)
		{
			return a + b;
		}
	}

	namespace Cube
	{
		long double Volume(long double a, long double b, long double c)
		{
			return a * b * c;
		}
	}
}

namespace PtrGeometry
{
	namespace Square
	{
		void Area(long double *ptr, long double a, long double b)
		{
			*ptr = a * b;
		}

		void Perimeter(long double *ptr, long double a, long double b)
		{
			*ptr = a + b;
		}
	}

	namespace Cube
	{
		void Volume(long double *ptr, long double a, long double b, long double c)
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
        	{
			return ERROR_NOERROR;
        	}

		else if(errorCode = ERROR_UNEXPECTEDERROR)
		{
			return ERROR_UNEXPECTEDERROR;
        	}

		else if(errorCode = ERROR_TYPEERROR)
		{
			return ERROR_TYPEERROR;
		}

		else if(errorCode = ERROR_ARGERROR)
		{
            		return ERROR_ARGERROR;
		}

		else if(errorCode = ERROR_FILEIOERROR)
		{
			return ERROR_FILEIOERROR;
        	}

		else if(errorCode = ERROR_OTHERERROR)
		{
			return ERROR_OTHERERROR;
		}

		*errorPtr = ERROR_NOERROR;
	}
}

#endif
