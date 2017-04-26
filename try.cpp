#include<iostream>
#include"PromptModule.h"
#include"ErrorHandlingModule.h"

using namespace std;
char GetOperator()
{
	char Operator='+';
	cout << "Operator: ";
	cin >> Operator;
	return Operator;
}

float GetOperand()
{
	float Operand =1;
	cout << "Operand: ";
	cin >> Operand;
	return Operand;
}

void Tape(const char theOperator,const float theOperand)
{
	static const int myTapeSize = 5;
	static char myOperator[myTapeSize];
	static float myOperand[myTapeSize];
	static int myNumberofEntries =0;

	if (theOperator != '?')
	{
		if (myNumberofEntries < myTapeSize)
		{
			myOperator[myNumberofEntries] = theOperator;
			myOperand[myNumberofEntries] = theOperand;
			myNumberofEntries++;
		}
		else
		{
			throw runtime_error 
			("Error - Out of room on the tape.");

		};
	}
	else
	{
		for
			(
			 int Index =0;
			 Index < myNumberofEntries;
			 Index++
			)
			{
				cout <<myOperator[Index]<<","<<
					myOperand[Index]<<
					endl;
			};
	};
};

float Accumulate(const char theOperator,const float theOperand)
{
	static float myAccumulator = 0;
	switch(theOperator)
	{
		case '+':
			myAccumulator =myAccumulator +theOperand;
			break;

		case '-':
			myAccumulator =myAccumulator - theOperand;
			break;

		case '*':
			myAccumulator = myAccumulator * theOperand;
			break;
			
		case '/':
			myAccumulator = myAccumulator / theOperand;
			break;
		case '?':
			break;
		default:
			throw
				runtime_error
				("Error - Invalid operator");
	};
	Tape(theOperator,theOperand);
	return myAccumulator;
}

int main(int argc, char* argv[])
{
	SAMSErrorHandling::Initialize();
	float ReturnCode=0;
	try
	{
		do
		{
			char Operator = GetOperator();
			float Operand = GetOperand();

			cout << Accumulate(Operator,Operand) <<endl;
		}
		while(SAMSPrompt::UserWantsToContinue("More?"));
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
