#include "RequestModule.h"

namespace SAMSCalculator
{
	aRequest::aRequest
		(
		 const anOperator theOperator,
		 const float theOperand
		):
			myOperator(theOperator),
			myOperand(theOperand)
	{
	};

	aRequest::aRequest
		(
		 const aRequest &theRequest
		):
			myOperator(theRequest.myOperator),
			myOperand(theRequest.myOperand)
	{
	};

	aRequest::anOperator aRequest::Operator(void) const
	{
		return myOperator;
	};

	float aRequest::Operand(void) const
	{
		return myOperand;
	};
};
