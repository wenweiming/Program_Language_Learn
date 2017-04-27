#include <iostream>
#include <fstream>

#include "TapeModule.h"
#include "AccumulatorModule.h"
#include "ErrorHandlingModule.h"

namespace SAMSCalculator
{
   using namespace std;

   struct aTapeElement
   {
      char Operator;
      float Operand;
      aTapeElement *NextElement;
   };

   void PrintTape(aTapeElement *theTapeRoot)
   {
      aTapeElement *CurrentTapeElement = theTapeRoot; // Start with the first Element

      while (CurrentTapeElement != NULL) // Continue down the list
      {
         cout <<
            CurrentTapeElement->Operator << "," <<
            CurrentTapeElement->Operand <<
            endl;

         CurrentTapeElement =
            CurrentTapeElement->NextElement; // Get ready to look at the next Element
      };
   }
   
   void DeleteTape(aTapeElement *theTapeRoot)
   {
      aTapeElement *CurrentTapeElement = theTapeRoot; // Start with the first Element

      while (CurrentTapeElement != NULL) // Move to release the next Element (if any)
      {
         aTapeElement *NextElement =
            CurrentTapeElement->NextElement; // Save for the next step

         delete CurrentTapeElement; // Delete the storage pointed to
         CurrentTapeElement = NextElement; // Get ready to look at the next Element
      };
   }

	void StreamTape
   (
   	const char *theTapeOutputStreamName,
      aTapeElement *theTapeRoot
   )
   {
      if ((theTapeOutputStreamName == NULL) || (theTapeRoot == NULL)) return;

      ofstream TapeOutputStream;

      try
      {
      	TapeOutputStream.exceptions
         	(TapeOutputStream.failbit);

         TapeOutputStream.open
         	(theTapeOutputStreamName,ios_base::out);

         aTapeElement *CurrentTapeElement = theTapeRoot;

         while (CurrentTapeElement != NULL)
         {
            TapeOutputStream <<
               CurrentTapeElement->Operator <<
               CurrentTapeElement->Operand;

            CurrentTapeElement =
            	CurrentTapeElement->NextElement;
         };

         TapeOutputStream.close();
      }
      catch (ios_base::failure &IOError)
      {
         SAMSErrorHandling::HandleOutputStreamError
         	(TapeOutputStream,IOError);
      };
   }

   void Tape
   (
      const char theOperator,
      const float theOperand,
      const char *theTapeOutputStreamName
   )
   {
      static aTapeElement *TapeRoot = NULL;

      if (theOperator == '?') // Print the tape
      {
         PrintTape(TapeRoot);
      }
      else if (theOperator == '.') // Program is terminating, release the storage
      {
			StreamTape(theTapeOutputStreamName,TapeRoot);
         DeleteTape(TapeRoot);
      }
      else // Normal operation: Add to the tape
      {
         aTapeElement *NewElement = new aTapeElement;

         NewElement->Operator = theOperator;
         NewElement->Operand = theOperand;
         NewElement->NextElement = NULL;

         if (TapeRoot == NULL) // This is the first Element
         {
            TapeRoot = NewElement;
         }
         else // Add the Element to the end of the last Element in the list
         {
            aTapeElement *CurrentTapeElement = TapeRoot;

            while (CurrentTapeElement->NextElement != NULL)
            {
               CurrentTapeElement = CurrentTapeElement->NextElement;
            };

            // CurrentTapeElement now contains the last Element in the list
            CurrentTapeElement->NextElement = NewElement;
         };
      };
   };
};
