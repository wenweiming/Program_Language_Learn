#include <iostream>
#include "TapeModule.h"

namespace SAMSCalculator
{
	using namespace std;

	void PrintTape(aTapeElement *theTapeRoot)
	{
		aTapeElement *CurrentTapeElement = theTapeRoot;

		while(CurrentTapeElement != NULL)
		{
			cout << CurrentTapeElement->Operator <<
				CurrentTapeElement->Operand <<
				endl;

			CurrentTapeElement=CurrentTapeElement->NextElement;
		}

	};

	void DeleteTape(aTapeElement *theTapeRoot)
	{
		aTapeElement *CurrentTapeElement = theTapeRoot;
		while(CurrentTapeElement == NULL)
		{
			aTapeElement *NextTapeElement = CurrentTapeElement->NextElement;
			delete CurrentTapeElement;
			CurrentTapeElement = NextTapeElement;
		}

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
