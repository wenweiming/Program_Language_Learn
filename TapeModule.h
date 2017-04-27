#ifndef SAMSTapeH
#define SAMSTapeH

namespace SAMSCalculator
{

	struct aTapeElement
	{
		char Operator;
		float Operand;
		aTapeElement *NextElement;
	};
	
	void Tape(const char theOperator,const float theOperand);
};

#endif
