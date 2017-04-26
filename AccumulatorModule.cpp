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
				Tape(theOperator,theOperand);
				break;
	
			case subtract:
				myAccumulator =myAccumulator - theOperand;
				Tape(theOperator,theOperand);
				break;
	
			case multiply:
				myAccumulator = myAccumulator * theOperand;
				Tape(theOperator,theOperand);
				break;
				
			case divide:
				myAccumulator = myAccumulator / theOperand;
				Tape(theOperator,theOperand);
				break;
	
			case reset:
				myAccumulator =theOperand;
				Tape(theOperator,theOperand);
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
}
