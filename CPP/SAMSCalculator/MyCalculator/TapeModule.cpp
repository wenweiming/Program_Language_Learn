#include <iostream>
#include <ios>
#include "TapeModule.h"
#include <fstream>
#include <exception>
#include "ErrorHandlingModule.h"

namespace SAMSCalculator
{
	using namespace std;

	void StreamTape(
			const char *theTapeOutputStreamName,
			aTapeElement *theTapeRoot
		       )
	{
		if (theTapeOutputStreamName == NULL) return;
		ofstream TapeOutputStream;

		try
		{
			TapeOutputStream.exceptions(TapeOutputStream.failbit);

			TapeOutputStream.open (theTapeOutputStreamName,ios_base::out);

			aTapeElement *CurrentTapeElement = theTapeRoot;

			while (CurrentTapeElement !=NULL)
			{
				TapeOutputStream << CurrentTapeElement->Operator << CurrentTapeElement->Operand;
				CurrentTapeElement=CurrentTapeElement->NextElement;
			};

			TapeOutputStream.close();
		}
		catch (ios_base::failure &IOError)
		{
			SAMSErrorHandling::HandleOutputStreamError(TapeOutputStream,IOError);
		};
	}




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

	void Tape(const char theOperator,
			const float theOperand,
			const char *theTapeOutputStreamName)
	{
		static aTapeElement *TapeRoot = NULL;
	
		if (theOperator == '?')
		{
			PrintTape(TapeRoot);
		}
		else if (theOperator == '.')
		{
			StreamTape(theTapeOutputStreamName,TapeRoot);
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
