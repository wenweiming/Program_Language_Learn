#include<iostream>
#include"ExternalInterfaceModule.h"
#include"AccumulatorModule.h"

using namespace std;
char GetOperator()
{
	char Operator;
	cin >> Operator;
	return Operator;
};

float GetOperand()
{
	float Operand;
	cin >> Operand;
	return Operand;
};

void DisplayValueOnConsole(float theValue)
{
	cout << endl << theValue << endl;
};

void DisplayMessageOnConsole(const char *theMessage)
{
	cout << theMessage <<endl;
};

int main(int argc, char* argv[])
{
	SAMSCalculator::aCalculatorExternalInterface CalculatorExternalInterface;
	
	CalculatorExternalInterface.GetAnOperator = GetOperator;

	CalculatorExternalInterface.GetAnOperand = GetOperand;

	CalculatorExternalInterface.HandleResults = DisplayValueOnConsole;

	CalculatorExternalInterface.DisplayMessage = DisplayMessageOnConsole;

	return SAMSCalculator::CalculateFromInput(CalculatorExternalInterface);
}
