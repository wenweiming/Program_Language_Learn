#ifndef CalculatorExternalInterfaceModuleH
#define CalculatorExternalInterfaceModuleH

namespace SAMSCalculator
{
	typedef char (*ToGetAnOperator)(void);
	typedef float (*ToGetAnOperand)(void);
	typedef void (*ToHandleResults)(const float theResult);
	typedef void (*ToDisplayMessage)(const char *theMessage);

	struct aCalculatorExternalInterface
	{
		ToGetAnOperator GetAnOperator;
		ToGetAnOperand GetAnOperand;
		ToHandleResults HandleResults;
		ToDisplayMessage DisplayMessage;
	};

	float CalculateFromInput
		(
		 aCalculatorExternalInterface theCalculatorExternalInterface
		);
	bool TestOk
		(
		 const char theOperator,
		 const float theOperand,
		 const float theExpectedResult
		);
	void SelfTest(void);
	bool NextCalculation
		(
		 const aCalculatorExternalInterface
		 &theCalculatorExternalInterface
		);

};

#endif
