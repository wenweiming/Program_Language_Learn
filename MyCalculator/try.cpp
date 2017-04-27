#include<iostream>
#include"PromptModule.h"
#include"ErrorHandlingModule.h"
#include"AccumulatorModule.h"
#include"TapeModule.h"

using namespace std;
SAMSCalculator::anOperator GetOperator()
{
	char Operator='+';
	cin >> Operator;
	return Operator;
}

float GetOperand()
{
	float Operand =1;
	cin >> Operand;
	return Operand;
}

void DisplayValueOnConsole(float theValue)
{
	cout << endl << theValue << endl;
}

void DisplayMessageOnConsole(const char *theMessage)
{
	cout << theMessage <<endl;
}

int main(int argc, char* argv[])
{
	SAMSErrorHandling::Initialize();
	float ReturnCode=0;
	SAMSCalculator::anOperator Operator;
	try
	{
		do
		{
			Operator = GetOperator();
			if
				(
				 Operator == '+' ||
				 Operator == '-' ||
				 Operator == '*' ||
				 Operator == '/' ||
				 Operator == '@' 
				)
				{
					 float Operand =GetOperand();
					 SAMSCalculator::Accumulator(Operator,Operand);
				}
			else if (Operator == '!')
			{
				SelfTest();
			}
			else if (Operator == '.')
			{
			}
			else
			{
				SAMSCalculator::Accumulator(Operator);
			};
		}
		while(Operator != '.');
		SAMSCalculator::Tape('.',0);
	}
	catch(runtime_error RuntimeError)
	{
		ReturnCode=SAMSErrorHandling::HandleRuntimeError(RuntimeError);
	}
	catch(...)
	{
		SAMSErrorHandling::HandleNotANumberError();
	};
	
	return ReturnCode;
}
