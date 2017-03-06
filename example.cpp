/* example.cpp
 * by Brendan Gowen
 *
 * Description: 
 * This is an example program that uses my header 
 * called everything.h with well-commented code.
 *
 * Goal:
 * Teach users how to use the everything.h header
 * and to create a calculator from it.
 *
 * Last Changed:
 * 3/6/16
 */ 

// This includes the everything.h header.

#include "everything.h"

// This sets the error level for checking later if any errors occur.

Error errorCode = ERROR_NOERROR;

// This is the global variable for the answer;

ldbl answer;

// This is the entry point.

int main(int argc, char *argv[])
{
	// The try block lets us throw our errorCode for checking.
	try
	{
		// Asks the user what operation they want to perform.
		
		string operation = IO::StrInput("What operation to you what to perform? ");
		
		// Asks the user for a number.
		
		ldbl numA = IO::lDblInput("Please enter a number. ");
		
		// Does the math for adding.
		
		if(operation == "add")
		{
			// Asks the user for another number.
			
			ldbl numB = IO::lDblInput("Please enter a number. ");
		
			// Does the math.
			
			PtrMath::Add(&answer, numA, numB);
		}
		
		// Does the math for subtracting.
		
		else if(operation == "subtract")
		{
			// Asks the user for another number.
			
			ldbl numB = IO::lDblInput("Please enter a number. ");
			
			// Does the math.
			
			PtrMath::Subtract(&answer, numA, numB);
		}
		
		// Does the math for multiplying.
		
		else if(operation == "multiply")
		{
			// Asks the user for another number.
			
			ldbl numB = IO::lDblInput("Please enter a number. ");
			
			// Does the math.
			
			PtrMath::Multiply(&answer, numA, numB);
		}
		
		// Does the math for dividing.
		
		else if(operation == "divide")
		{
			// Asks the user for another number.
			
			ldbl numB = IO::lDblInput("Please enter a number. ");
			
			// Does the math.
			
			PtrMath::Divide(&answer, numA, numB);
		}
		
		else
		{
			// This sets the errorCode to a TYPEERROR because what
			// was typed in did not match the options marked above.
			
			errorCode = ERROR_TYPEERROR;
			
			// Throws the errorCode.
			
			throw errorCode;
		}
		
		// If all goes well, print the answer.
		
		cout << "The answer is: " << answer << ".\n";
		
		// Throws the errorCode for checking.
		
		throw errorCode;
	}
	
	// Catches the errorCode when we throw it from the try block.
	
	catch(Error errorCode)
	{
		// Convert the error into a integer and return its value.
		
		return static_cast<int>(errorCode);
	}
	
	// Catches unexpected errors and returns t- 
	// he equivalent of ERROR_UNEXPECTEDERROR.
	
	catch(...)
	{
		// Return unexpected error because compiler co-
		// mplains that the Error enum is not in scope.
		
		return -1;
	}
}
