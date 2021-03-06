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

	void PrintTape(aTapeElement *theTapeElement);

	void DeleteTape(aTapeElement *theTapeElement);
	
	void Tape(const char theOperator,
		  const float theOperand=0,
		  const char *theTapeOutputStreamName = NULL);

	void TapeStream(
			const char *theTapeOutputStreamName,
			aTapeElement *theTapeRoot);

};

#endif
