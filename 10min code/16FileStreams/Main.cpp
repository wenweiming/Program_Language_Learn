#include <iostream>
#include <ios>
#include <fstream> 

#include "PromptModule.h"
#include "ErrorHandlingModule.h"
#include "AccumulatorModule.h"
#include "TapeModule.h"
#include "ExternalInterfaceModule.h"

using namespace std;

ifstream TapeInputStream; // Global variable for callback

char GetOperator(void)
{
   char Operator;

   if
   	(
      	TapeInputStream.is_open() &&
         (!TapeInputStream.eof())
      )
   {
		TapeInputStream >> Operator;
   }
   else
   {
		cin >> Operator;
   };

   return Operator;
}

float GetOperand(void)
{
   float Operand = 1;

   if
   	(
      	TapeInputStream.is_open() &&
         (!TapeInputStream.eof())
      )
   {
   	TapeInputStream >> Operand;
   }
   else
   {
      cin >> Operand;
   };

   return Operand;
}

void DisplayValueOnConsole(float theValue)
{
	cout << endl << theValue << endl;
}

int main(int argc, char* argv[])
{
	SAMSErrorHandling::Initialize();

   if (argc > 1) // A file name is present
   {
      try
      {
      	TapeInputStream.exceptions(cin.failbit);
         TapeInputStream.open(argv[1],ios_base::in);
      }
      catch (ios_base::failure &IOError)
      {
			// File does not exist
         // The stream will be unopened
         // but the failure bits will not be set
      };

   }; // otherwise, the stream exists
   	// but is closed and cannot be used;

   SAMSCalculator::aCalculatorExternalInterface
   	CalculatorExternalInterface;

   CalculatorExternalInterface.GetAnOperator =
   	GetOperator;

   CalculatorExternalInterface.GetAnOperand =
   	GetOperand;

   CalculatorExternalInterface.HandleResults =
   	DisplayValueOnConsole;

	int Result = SAMSCalculator::CalculateFromInput
   	(CalculatorExternalInterface);

   // Don't leave the file open, because otherwise Tape()
   // will not be able to stream the current session
   TapeInputStream.close();

   // Stream and delete the tape
   SAMSCalculator::Tape('.',0,argv[1]);

   return Result;
}
