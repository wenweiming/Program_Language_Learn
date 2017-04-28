#include<iostream>
#include<ios>
#include<fstream>

#include"ExternalInterfaceModule.h"
#include"AccumulatorModule.h"
#include"ErrorHandlingModule.h"
#include"TapeModule.h"
#include"PromptModule.h"

using namespace std;
ifstream TapeInputStream;

char GetOperator()
{
	char Operator;

	if
		(
		 TapeInputStream.is_open() &&
		 (!TapeInputStream.eof())
		)
		{
			TapeInputStream>>Operator;
		}
	else
	{
		cin >> Operator;
	};
	return Operator;
};

float GetOperand()
{
	float Operand;

	if
		(
		 TapeInputStream.is_open() &&
		 (!TapeInputStream.eof())
		)
		{
			TapeInputStream>>Operand;
		}
	else
	{
		cin >> Operand;
	};
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

int main(int argc, char *argv[])
{
	SAMSErrorHandling::Initialize();

	ifstream fin(argv[1]);

	if (argc >1)
	{
		try
		{
			TapeInputStream.exceptions(cin.failbit);
			
			if (!fin)
			{
			}
			else
			{
				TapeInputStream.open(argv[1],ios_base::in);
			};
		}
		catch (ios_base::failure &IOError)
		{
			SAMSErrorHandling::HandleInputStreamError(TapeInputStream,IOError);
		};
	};

	SAMSCalculator::aCalculatorExternalInterface CalculatorExternalInterface;
	
	CalculatorExternalInterface.GetAnOperator = GetOperator;

	CalculatorExternalInterface.GetAnOperand = GetOperand;

	CalculatorExternalInterface.HandleResults = DisplayValueOnConsole;

	CalculatorExternalInterface.DisplayMessage = DisplayMessageOnConsole;

	int Result = SAMSCalculator::CalculateFromInput(CalculatorExternalInterface);
	
	if (!fin)
	{
	}
	else
	{
		TapeInputStream.close();
	};

	SAMSCalculator::Tape('.',0,argv[1]);

	return Result;
}
