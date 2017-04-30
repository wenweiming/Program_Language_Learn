#include <iostream>

#include "TapeModule.h"
#include "AccumulatorModule.h"

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
      // Start with the first Element
      aTapeElement *CurrentTapeElement = theTapeRoot;

      // Continue down the list
      while (CurrentTapeElement != NULL)
      {
         cout <<
            CurrentTapeElement->Operator << "," <<
            CurrentTapeElement->Operand <<
            endl;

         // Get ready to look at the next Element
         CurrentTapeElement =
            CurrentTapeElement->NextElement;
      };
   }

   void DeleteTape(aTapeElement *theTapeRoot)
   {
      // Start with the first Element
      aTapeElement *CurrentTapeElement = theTapeRoot;

      // Move to release the next Element (if any)
      while (CurrentTapeElement != NULL)
      {
         // Save next element for the next step
         aTapeElement *NextElement =
            CurrentTapeElement->NextElement;

         delete CurrentTapeElement;

         // Get ready to look at the next Element
         // using the saved pointer
         CurrentTapeElement = NextElement;
      };
   }

   void Tape
   	(const char theOperator,const float theOperand)
   {
      static aTapeElement *TapeRoot = NULL;

      if (theOperator == '?') // Print the tape
      {
         PrintTape(TapeRoot);
      }
      else if (theOperator == '.') // Program is stopping
      {
         DeleteTape(TapeRoot);
      }
      else // Normal operation: Add to the tape
      {
         aTapeElement *NewElement = new aTapeElement;

         NewElement->Operator = theOperator;
         NewElement->Operand = theOperand;
         NewElement->NextElement = NULL;

         if (TapeRoot == NULL)
         {
         	// This is the first Element
            TapeRoot = NewElement;
         }
         else
         {
         	// Add the Element to the end of the
            // last Element in the list

            // Start at the beginning...
            aTapeElement *CurrentTapeElement = TapeRoot;

            // ...skip to the end
            while
               (
                  CurrentTapeElement->NextElement != NULL
               )
            {
               CurrentTapeElement =
               	CurrentTapeElement->NextElement;
            };

            // CurrentTapeElement is the last Element
            // Add to it...
            CurrentTapeElement->NextElement = NewElement;
         };
      };
   };
};
