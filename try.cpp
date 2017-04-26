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

void DisplayValueOnConsole(float theValue)
{
	cout << endl << theValue << endl;
}

void DisplayMessageOnConsole(const char *theMessage)
{
	cout << theMessage <<endl;
}


struct aTapeElement
{
	char Operator;
	float Operand;
	aTapeElement *NextElement;
}


void Tape(const char theOperator,const float theOperand)
{
	static aTapeElement *TapeRoot = NULL;

	if (theOperator == '?')
	{
		PrintTape(TapeRoot);
	}
	else if (theOperand == '.')
	{
		DeleteTape(TapeRoot);
	}
	else
	{
		aTapeElement *NewElement = new aTapeElement;
		NewElement->Operator = theOperator;
		NewElement->Operand = theOperand;
		NewElement->NextElement =NULL;

		if (TapeRoot == NULL)
		{
			TapeRoot = NewElement;
		}
		else
		{
			aTapeElement *CurrentTapeElement = TapeRoot;
			while 
				(
				 CurrentTapeElement->NextElement != NULL
				)
				{
					CurrentTapeElement=
						CurrentTapeElement->NextElement;
				};
			CurrentTapeElement->NextElement = NewElement;
		};
	};
};

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
