#include <iostream>
#include "TapeModule.h"

namespace SAMSCalculator
{
	using namespace std;

	void PrintTape(aTapeElement *theTapeElement)
	{
		cout << *theTapeElement.Operator <<
			*theTapeElement.Operand <<
			endl;

	};

	void DeleteTape(aTapeElement *theTapeElement)
	{

	};

	void Tape(const char theOperator,const float theOperand)
	{
		static aTapeElement *TapeRoot = NULL;
	
		if (theOperator == '?')
		{
			PrintTape(TapeRoot);
		}
		else if (theOperand == '.')
		{
			DeleteTape(TapeRoot);
		}
		else
		{
			aTapeElement *NewElement = new aTapeElement;
			NewElement->Operator = theOperator;
			NewElement->Operand = theOperand;
			NewElement->NextElement =NULL;
	
			if (TapeRoot == NULL)
			{
				TapeRoot = NewElement;
			}
			else
			{
				aTapeElement *CurrentTapeElement = TapeRoot;
				while 
					(
					 CurrentTapeElement->NextElement != NULL
					)
					{
						CurrentTapeElement=
							CurrentTapeElement->NextElement;
					};
				CurrentTapeElement->NextElement = NewElement;
			};
		};
	};
};
