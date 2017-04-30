#include<iostream>
#include<exception>
#include<string>

#include"AccumulatorModule.h"
namespace SAMSCalculator
{
	using namespace std;
	
	anAccumulator::anAccumulator
		(
		 void
		):
			myValue(0)
	{
	};

	anAccumulator::anAccumulator
		(
		 anAccumulator &theAccumulator
		):
			myValue(theAccumulator.myValue)
	{
	};

	float anAccumulator::Apply(const aRequest &theRequest)
	{
		static (theRequest.Operator())
		{
			case aRequest::add:
				myValue+= theRequest.Operand();
				break;
	
			case aRequest::subtract:
				myValue-= theRequest.Operand();
				break;
	
			case aRequest::multiply:
				myValue*= theRequest.Operand();
				break;
				
			case aRequest::divide:
				myValue/= theRequest.Operand();
				break;
	
			//case reset:
			//	myAccumulator =theOperand;
			//	break;

			//case query:
			//	break;
			default:
				throw
					runtime_error
					(
					 string("SAMSCalculator::")+
					 string("anAccumulator::")+
					 string("Apply")+
					 string("- Unknown Operator.")
					 );
		};
		return Value();
	};

	float anAccumulator::Value(void) const
	{
		return myValue;
	};
};
