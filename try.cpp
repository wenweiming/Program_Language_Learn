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
	static const int myTapeChunk = 5;

	static char *myOperator = new char[myTapeChunk];
	static int *myOperand = new int[myTapeChunk];

	static int myTapeSize = myTapeChunk;
	static int myNumberofEntries = 0;

	switch (theOperator)
	{
		case '?':
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
			break;
			
		case '.':
			delete [] myOperator;
			delete [] myOperand;
			break;

		default:

			if (myNumberofEntries == myTapeSize)
			{
				char *ExpandedOperator =
					new char[myNumberofEntries + myTapeChunk];
				int * ExpandedOperand =
					new int [myNumberofEntries + myTapeSize];
				char *FromOperator = myOperator;
				int *FromOperand = myOperand;

				char *ToOperator = ExpandedOperator;
				int *ToOperand = ExpandedOperand;

				for
					(
					 int Index =0;
					 Index < myNumberofEntries;
					 Index++
					)
					{
						*ToOperator++ = *FromOperator++;
						*ToOperand++ = *FromOperand++;
					};
				delete [] myOperator;
				delete [] myOperand;

				myOperator = ExpandedOperator;
				myOperand = ExpandedOperand;

				myTapeSize += myTapeChunk;
			};

			myOperator[myNumberofEntries] = theOperator;
			myOperand[myNumberofEntries] = theOperand;
			myNumberofEntries++;
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
