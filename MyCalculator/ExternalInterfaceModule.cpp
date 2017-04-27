#include<iostream>
#include"ErrorHandlingModule.h"
#include"TapeModule.h"
#include"AccumulatorModule.h"
#include"ExternalInterfaceModule.h"

namespace SAMSCalculator
{
	using namespace std;
	bool TestOk(
			const anOperator theOperator,
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
		float OldValue = Accumulator(query);
		try
		{
			if
				(
				 TestOk(reset,0,0) &&
				 TestOk(add,3,3) &&
				 TestOk(subtract,2,1) &&
				 TestOk(multiply,4,4) &&
				 TestOk(divide,2,2)
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
		Accumulator(reset,OldValue);
	}

	bool NextCalculation
		(
		 const aCalculatorExternalInterface
		 &theCalculatorExternalInterface
		)
		{
			char Operator = theCalculatorExternalInterface.GetAnOperator();

			switch (Operator)
			{
				case '.':
				{
					return true;
				};
				case '?':
				{
					Tape(Operator);
					return false;
				};
				case '=':
				case '@':
				{
					anOperator OperatorValue =
						Operator == '=' ? query:
						reset;
					float Result = Accumulator(OperatorValue);
					if (OperatorValue == query)
					{
						theCalculatorExternalInterface.HandleResults(Result);
					};
					return false;
				};
				case '+':
				case '-':
				case '*':
				case '/':
				{
					float Number = theCalculatorExternalInterface.GetAnOperand();
					anOperator OperatorValue =
						Operator == '+' ? add:
						Operator == '-' ? subtract:
						Operator == '*' ? multiply:
						divide;
					Accumulator(OperatorValue,Number);
					Tape(Operator,Number);
					return false;
				};
				case '!':
				{
					SelfTest();
					return false;
				}
				default:
				{
					throw runtime_error
						("Error - Invalid operator.");
				};
			};
		};
	float CalculateFromInput
		(
		 aCalculatorExternalInterface theCalculatorExternalInterface
		 )
		{
			SAMSErrorHandling::Initialize();

			bool Done = false;

			do
			{
				try
				{
					Done = NextCalculation(theCalculatorExternalInterface);
				}
				catch (runtime_error RuntimeError)
				{
					SAMSErrorHandling::HandleRuntimeError(RuntimeError);
				}
				catch (...)
				{
					SAMSErrorHandling::HandleNotANumberError();
				};
			}
			while (!Done);

			Tape('.');

			return 0;
		};
};
