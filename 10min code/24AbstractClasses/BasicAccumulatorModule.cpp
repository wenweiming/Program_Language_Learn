#include <string>
#include <exception>

#include "BasicAccumulatorModule.h"

namespace SAMSCalculator
{
   using namespace std;

   aBasicAccumulator::aBasicAccumulator(void)
   {
   };

   aBasicAccumulator::aBasicAccumulator(aBasicAccumulator &theAccumulator):
   	anAccumulator(theAccumulator)
   {
   };

   float aBasicAccumulator::Apply(const aRequest &theRequest)
   {
   	switch (theRequest.Operator())
      {
      	case aRequest::add:			myValue+= theRequest.Operand(); break;
      	case aRequest::subtract:	myValue-= theRequest.Operand(); break;
      	case aRequest::multiply:	myValue*= theRequest.Operand(); break;
      	case aRequest::divide:		myValue/= theRequest.Operand(); break;

         default:

         	throw
            	runtime_error
               (
               	string("SAMSCalculator::aBasicAccumulator::") +
                  string("Apply") +
                  string(" - Unknown operator to be applied.")
               );
      };

      return Value();
   };

   float aBasicAccumulator::Value(void) const
   {
   	return myValue;
   };

	anAccumulator &aBasicAccumulator::ReferenceToANewAccumulator(void)
   {
   	return *(new aBasicAccumulator);
   };

};
