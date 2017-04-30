#ifndef BasicAccumulatorModuleH
#define BasicAccumulatorModuleH

#include <string>
#include <exception>

#include "AccumulatorModule.h"
#include "InstanceCountableModule.h"

namespace SAMSCalculator
{
	template <class ofType> class aBasicAccumulator:
   	public anAccumulator<ofType>,
      public isInstanceCountable
   {
   	public:

      	aBasicAccumulator(void);

         aBasicAccumulator
         	(aBasicAccumulator &theAccumulator);

         ofType Apply(const aRequest<ofType> &theRequest);
         ofType Value(void) const;

         anAccumulator<ofType>
         	&ReferenceToANewAccumulator(void);
	};

   using namespace std;

   template <class ofType>
   	aBasicAccumulator<ofType>::aBasicAccumulator(void)
   {
   };

   template <class ofType>
   	aBasicAccumulator<ofType>::aBasicAccumulator
      	(aBasicAccumulator<ofType> &theAccumulator):
   			anAccumulator(theAccumulator)
   {
   };

   template <class ofType>
   	ofType aBasicAccumulator<ofType>::Apply
      	(const aRequest<ofType> &theRequest)
   {
   	switch (theRequest.Operator())
      {
      	case add:
         	myValue+= theRequest.Operand();
            break;

      	case subtract:
         	myValue-= theRequest.Operand();
            break;

      	case multiply:
         	myValue*= theRequest.Operand();
            break;

      	case divide:
         	myValue/= theRequest.Operand();
            break;

         default:

         	throw
            	runtime_error
               (
               	string("SAMSCalculator::") +
                  string("aBasicAccumulator<ofType>::") +
                  string("Apply") +
                  string(" - Unknown operator.")
               );
      };

      return Value();
   };

   template <class ofType>
   	ofType aBasicAccumulator<ofType>::Value(void) const
   {
   	return myValue;
   };

	template <class ofType>
   	anAccumulator<ofType>
      	&aBasicAccumulator<ofType>::
         	ReferenceToANewAccumulator(void)
   {
   	return *(new aBasicAccumulator<ofType>);
   };
};

#endif
