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
         "Input error - input may not have been a number." <<
         endl;

      cin.clear(); // Clear the error state from the stream

      // Eat the bad input so we can pause the program
      char BadInput[5];
      cin >> BadInput;

      return 1;
   };

   int HandleRuntimeError(runtime_error theRuntimeError)
   {
      cerr <<
         theRuntimeError.what() <<
         endl;

      return 1;
   };

   int HandleInputStreamError(ifstream &theStream,ios_base::failure &theIOError)
   {
      cerr << "Input error - " << theIOError.what() << endl;
      theStream.clear();

      return 1;
   };

   int HandleOutputStreamError(ofstream &theStream,ios_base::failure &theIOError)
   {
      cerr << "Output error - " << theIOError.what() << endl;
      theStream.clear();

      return 1;
   };
}