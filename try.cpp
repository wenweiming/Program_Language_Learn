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
		default:
			throw
				runtime_error
				("Error - Invalid operator");
	};
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
