#include <exception>
#include <ios>

#include "AccumulatorModule.h"

namespace SAMSCalculator
{
	using namespace std;

   float Accumulator(const anOperator theOperator,const float theOperand)
   {
      static float myAccumulator = 0; // Initialized to 0 when the program starts

      switch (theOperator)
      {
         case add: 		myAccumulator = myAccumulator + theOperand; break;
         case subtract: myAccumulator = myAccumulator - theOperand; break;
         case multiply: myAccumulator = myAccumulator * theOperand; break;
         case divide: 	myAccumulator = myAccumulator / theOperand; break;
         case reset: 	myAccumulator = theOperand; break;
         case query: 	break; // We always return the result - do nothing

         default:
            throw
               runtime_error
                  ("Error - Invalid operator");
      };

      return myAccumulator;
   };
};
