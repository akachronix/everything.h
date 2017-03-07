/* template.cpp
 * by Brendan Gowen
 *
 * Description:
 * A template that sets up all the error handling for you.
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

#include "everything.h"

Error errorCode = ERROR_NOERROR;

int main(int argc, char *argv[])
{
	try
	{
		throw errorCode;	
	}
	
	catch(Error errorCode)
	{
		switch(static_cast<int>(errorCode))
		{
			case 0:
				break;
			case -1:
				cout << "\n\nUnexpected error occurred.\n";
			case -2:
				cout << "\n\nType error occurred.\n";
			case -3:
				cout << "\n\nArgument error occurred.\n";
			case -4:
				cout << "\n\nFile I/O error occurred.\n";
			case -5:
				cout << "\n\nOther error occurred.\n";
			default:
				break;
		}
		
		return static_cast<int>(errorCode);
	}
	
	catch(...)
	{
		return -1;
	}
	
	return 0;
}
