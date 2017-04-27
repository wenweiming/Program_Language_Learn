#include "ConsoleAndPersistentTapeExternalInterfaceModule.h"

namespace SAMSCalculator
{
	using namespace std;

   aConsoleAndPersistentTapeExternalInterface::aConsoleAndPersistentTapeExternalInterface(void)
   {
      throw
         runtime_error
         (
            string("The default constructor for aConsoleAndPersistentTapeExternalInterface has been used. ") +
            string("Use only the constructor that requires the file path.")
         );
   };

   aConsoleAndPersistentTapeExternalInterface::aConsoleAndPersistentTapeExternalInterface(const char *theTapeSourceFilePath)
   {
   	if (theTapeSourceFilePath != "")
      {
      	myTapeSourceInputStream.open(theTapeSourceFilePath,ifstream::in);
      };
   };

   char aConsoleAndPersistentTapeExternalInterface::GetOperatorChar(void)
   {
   	if (myTapeSourceInputStream.is_open() && !myTapeSourceInputStream.eof())
      {
      	char OperatorChar;
      	myTapeSourceInputStream >> OperatorChar;

         if (OperatorChar == '\0') // The file is empty
         {
            myTapeSourceInputStream.close();
            return aConsoleOnlyExternalInterface::GetOperatorChar();
      	}
         else
         {
         	return OperatorChar;
         };
      }
      else
      {
      	if (myTapeSourceInputStream.is_open()) myTapeSourceInputStream.close();
      	return aConsoleOnlyExternalInterface::GetOperatorChar();
      };
   };

   float aConsoleAndPersistentTapeExternalInterface::GetOperand(void)
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
      	return aConsoleOnlyExternalInterface::GetOperand();
      };
   };
};
