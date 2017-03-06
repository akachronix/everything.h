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
		return static_cast<int>(errorCode);
	}
	
	catch(...)
	{
		return -1;
	}
	
	return 0;
}
