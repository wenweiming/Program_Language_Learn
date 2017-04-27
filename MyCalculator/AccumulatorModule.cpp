#include<iostream>
#include<exception>

#include"AccumulatorModule.h"
namespace SAMSCalculator
{
	using namespace std;

	float Accumulator(const anOperator theOperator,const float theOperand)
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
				break;
			default:
				throw
					runtime_error
					("Error - Invalid operator");
		};
		return myAccumulator;
	};
};
