#include<iostream>
#include<exception>

#include"AccumulatorModule.h"
namespace SAMSCalculator
{
	using namespace std;

	float Accumulator(const char theOperator,const float theOperand = 0)
	{
		static float myAccumulator = 0;
		switch(theOperator)
		{
			case add:
				myAccumulator =myAccumulator +theOperand;
				break;
	
			case subtract:
				myAccumulator =myAccumulator - theOperand;
				break;
	
			case multiply:
				myAccumulator = myAccumulator * theOperand;
				break;
				
			case divide:
				myAccumulator = myAccumulator / theOperand;
				break;
	
			case reset:
				myAccumulator =theOperand;
				break;
			case query:
				cout << endl << myAccumulator <<endl;
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
}
