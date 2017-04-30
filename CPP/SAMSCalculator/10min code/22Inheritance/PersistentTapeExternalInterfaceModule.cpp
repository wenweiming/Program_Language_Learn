#include "PersistentTapeExternalInterfaceModule.h"

namespace SAMSCalculator
{
	using namespace std;

   aPersistentTapeExternalInterface::aPersistentTapeExternalInterface(void)
   {
      throw
         runtime_error
         (
            string("The default constructor for aPersistentTapeExternalInterface has been used. ") +
            string("Use only the constructor that requires the file path.")
         );
   };

   aPersistentTapeExternalInterface::aPersistentTapeExternalInterface(const char *theTapeSourceFilePath)
   {
   	if (theTapeSourceFilePath != "")
      {
      	myTapeSourceInputStream.open(theTapeSourceFilePath,ifstream::in);
      };
   };

   char aPersistentTapeExternalInterface::GetOperatorChar
   	(void)
   {
   	if
      	(
         	myTapeSourceInputStream.is_open() &&
            !myTapeSourceInputStream.eof()
         )
      {
      	char OperatorChar;
      	myTapeSourceInputStream >> OperatorChar;

         if (OperatorChar == '\0') // The file is empty
         {
            myTapeSourceInputStream.close();
            return anExternalInterface::GetOperatorChar();
      	}
         else
         {
         	return OperatorChar;
         };
      }
      else
      {
      	if (myTapeSourceInputStream.is_open())
         {
         	myTapeSourceInputStream.close();
         };

      	return anExternalInterface::GetOperatorChar();
      };
   };

   float aPersistentTapeExternalInterface::GetOperand(void)
   {
   	if (myTapeSourceInputStream.is_open() && !myTapeSourceInputStream.eof())
      {
      	float Operand;
      	myTapeSourceInputStream >> Operand;
         return Operand;
      }
      else
      {
      	if (myTapeSourceInputStream.is_open()) myTapeSourceInputStream.close();
      	return anExternalInterface::GetOperand();
      };
   };
};
