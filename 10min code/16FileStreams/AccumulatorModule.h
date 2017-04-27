#ifndef AccumulatorModuleH
#define AccumulatorModuleH

namespace SAMSCalculator
{
	enum anOperator {add,subtract,multiply,divide,reset,query};
	float Accumulator(const anOperator theOperator,const float theOperand = 0);
};

#endif
