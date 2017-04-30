#include <iostream>

#include "ExternalInterfaceModule.h"
#include "TapeModule.h"
#include "AccumulatorModule.h"
#include "ErrorHandlingModule.h"

namespace SAMSCalculator
{
   using namespace std;

   bool TestOK
   (
   	const char theCharacterOperator,
      const anOperator theOperator,
      const float theOperand,
      const float theExpectedResult
   )
   {
      float Result = Accumulator(theOperator,theOperand);

      if (Result == theExpectedResult)
      {
         cout << theCharacterOperator << theOperand << " - succeeded." << endl;
         return true;
      }
      else
      {
         cout <<
            theCharacterOperator << theOperand << " - failed. " <<
            "Expected " << theExpectedResult << ", got " << Result <<
            endl;

         return false;
      };
   }

   void SelfTest(void)
   {
      float OldValue = Accumulator(query);

      try
      {
         if
            (
               TestOK('@',reset,0,0) &&
               TestOK('+',add,3,3) &&
               TestOK('-',subtract,2,1) &&
               TestOK('*',multiply,4,4) &&
               TestOK('/',divide,2,2)
            )
         {
            cout << "Test completed successfully." << endl;
         }
         else
         {
            cout << "Test failed." << endl;
         };
      }
      catch (...)
      {
         cout << "An exception occured during self test." << endl;
      };

      Accumulator(reset,OldValue);
   }

   bool NextCalculation
   (
      const aCalculatorExternalInterface &theCalculatorExternalInterface
   )
   {
      char Operator = theCalculatorExternalInterface.GetAnOperator();

      switch (Operator) // This switch uses return instead of break
      {
         case '.': // Stop
         {
            return true;
         };

         case '?': // Show the tape
         {
            Tape(Operator);
            return false;
         };

         // Current value, self test and reset
         case '=': case '@':
         {
            anOperator OperatorValue =
               Operator == '=' ? query :
                                 reset;

            int Result = Accumulator(OperatorValue);

            if (OperatorValue == query)
            {
               theCalculatorExternalInterface.HandleResults(Result);
            };

            return false;
         };

         case '+': case '-': case '*': case '/':
         {
            int Number = theCalculatorExternalInterface.GetAnOperand();

            anOperator OperatorValue =
               Operator == '+' ? add :
               Operator == '-' ? subtract :
               Operator == '*' ? multiply :
                                 divide;

            Accumulator(OperatorValue,Number);
            Tape(Operator,Number);

            return false;
         };

         case '!':

         	SelfTest();
            return false;

         default: // Anything else is an error
         {
            throw runtime_error("Error - Invalid operator.");
         };
      };
   }

   int CalculateFromInput
   (
      aCalculatorExternalInterface &theCalculatorExternalInterface
   )
   {
      SAMSErrorHandling::Initialize();

      bool Done = false;

      do
      {
         try
         {
            Done = NextCalculation(theCalculatorExternalInterface);
         }
         catch (runtime_error RuntimeError)
         {
            SAMSErrorHandling::HandleRuntimeError(RuntimeError);
         }
         catch (...)
         {
            SAMSErrorHandling::HandleNotANumberError();
         };
      }
      while (!Done); // Continue

      return 0;
   };
};
