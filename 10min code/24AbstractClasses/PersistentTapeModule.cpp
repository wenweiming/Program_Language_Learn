#include <fstream>
#include <exception>
#include <string>

#include "PersistentTapeModule.h"

namespace SAMSCalculator
{
	using namespace std;

   aPersistentTape::aPersistentTape(void)
   {
      throw
         runtime_error
         (
            string("The default constructor for aPersistentTape has been used. ") +
            string("Use only the constructor that requires the file path.")
         );
   };

   aPersistentTape::aPersistentTape(const char *theOutputFilePath):
      myOutputFilePath(theOutputFilePath)
   {
   };

   aPersistentTape::~aPersistentTape(void)
   {
   	if (myOutputFilePath.size() > 0)
      {
         ofstream OutputStream(myOutputFilePath.c_str(),ofstream::out);

         int NumberOfTapeElements = NumberOfElements();

         for (int Index = 0; Index < NumberOfTapeElements; Index++)
         {
            OutputStream << Element(Index).OperatorCharacter() << Element(Index).Operand();
         };
      };
   };
};
