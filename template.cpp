/* template.cpp
 * by Brendan Gowen
 *
 * Description:
 * A template that sets up all the error handling for you.
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
