#include <iostream>

#include "ErrorHandlingModule.h"

namespace SAMSErrorHandling
{
	using namespace std;

   void Initialize(void)
   {
      cin.exceptions(cin.failbit);
   }

   int HandleNotANumberError(void)
   {
      cerr <<
         "Error - input may not have been a number." <<
         endl;

      cin.clear(); // Clear the error state

      // Eat the bad input so we can pause the program
      char BadInput[5];
      cin >> BadInput;

      return 1;
   }

   int HandleRuntimeError(runtime_error theRuntimeError)
   {
      cerr <<
         theRuntimeError.what() <<
         endl;

      return 1;
   }

}