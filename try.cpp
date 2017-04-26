#include<iostream>
#include"PromptModule.h"
#include"ErrorHandlingModule.h"

using namespace std;
char GetOperator()
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


void Tape(const char theOperator,const float theOperand)
{
	static const int myTapeChunk = 3;

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

float Accumulator(const char theOperator,const float theOperand = 0)
{
	static float myAccumulator = 0;
	switch(theOperator)
	{
		case '+':
			myAccumulator =myAccumulator +theOperand;
			Tape(theOperator,theOperand);
			break;

		case '-':
			myAccumulator =myAccumulator - theOperand;
			Tape(theOperator,theOperand);
			break;

		case '*':
			myAccumulator = myAccumulator * theOperand;
			Tape(theOperator,theOperand);
			break;
			
		case '/':
			myAccumulator = myAccumulator / theOperand;
			Tape(theOperator,theOperand);
			break;

		case '@':
			myAccumulator =theOperand;
			Tape(theOperator,theOperand);
			break;
		case '=':
			cout << endl << myAccumulator <<endl;
			break;
		case '?':
			Tape (theOperator,0);
			break;
		default:
			throw
				runtime_error
				("Error - Invalid operator");
	};
	return myAccumulator;
}

bool TestOk(
		const char theOperator,
		const float theOperand,
		const float theExpectedResult
	   )
{
	float Result = Accumulator(theOperator,theOperand);
	if (Result == theExpectedResult)
	{
		cout << theOperator << theOperand <<
			" - succeeded." <<endl;
		return true;
	}
	else
	{
		cout << theOperator << theOperand << "- failed." <<
			"Expected " << theExpectedResult <<
			", got" << Result <<
			endl;
		return false;
	};
}

void SelfTest(void)
{
	float OldValue = Accumulator('=');
	try
	{
		if
			(
			 TestOk('@',0,0) &&
			 TestOk('+',3,3) &&
			 TestOk('-',2,1) &&
			 TestOk('*',4,4) &&
			 TestOk('/',2,2)
			)
			{
				cout << "Test Completed successful." <<endl;
			}
		else
		{
			cout << "Test failed." <<endl;
		};
	}
	catch(...)
	{
		cout << "An exception occured during self test." << endl;
	};
	Accumulator('@',OldValue);
}

int main(int argc, char* argv[])
{
	SAMSErrorHandling::Initialize();
	float ReturnCode=0;
	char Operator;
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
					 Accumulator(Operator,Operand);
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
				Accumulator(Operator);
			};
		}
		while(Operator != '.');
		Tape('.',0);
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
