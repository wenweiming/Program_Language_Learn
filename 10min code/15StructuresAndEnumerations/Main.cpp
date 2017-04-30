#include <iostream>

#include "PromptModule.h"
#include "ErrorHandlingModule.h"
#include "AccumulatorModule.h"
#include "TapeModule.h"
#include "ExternalInterfaceModule.h"

using namespace std;

char GetOperator(void)
{
   char Operator;
   cin >> Operator;

   return Operator;
}

float GetOperand(void)
{
   float Operand;
   cin >> Operand;

   return Operand;
}

void DisplayValueOnConsole(float theValue)
{
	cout << endl << theValue << endl;
}

void DisplayMessageOnConsole(const char *theMessage)
{
	cout << theMessage << endl;
}

int main(int argc, char* argv[])
{
   SAMSCalculator::aCalculatorExternalInterface
   	CalculatorExternalInterface;

   CalculatorExternalInterface.GetAnOperator =
   	GetOperator;

   CalculatorExternalInterface.GetAnOperand =
   	GetOperand;

   CalculatorExternalInterface.HandleResults =
   	DisplayValueOnConsole;

   CalculatorExternalInterface.DisplayMessage =
   	DisplayMessageOnConsole;

	return SAMSCalculator::CalculateFromInput
   	(CalculatorExternalInterface);
}
