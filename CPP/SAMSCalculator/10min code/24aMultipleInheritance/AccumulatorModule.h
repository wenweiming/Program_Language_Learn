#ifndef AccumulatorModuleH
#define AccumulatorModuleH

#include "RequestModule.h"

namespace SAMSCalculator
{
	class anAccumulator
   {
   	public:

      	anAccumulator(void);
         anAccumulator(anAccumulator &theAccumulator);

         virtual float Apply(const aRequest &theRequest) = 0;
         virtual float Value(void) const = 0;

         virtual anAccumulator &ReferenceToANewAccumulator(void) = 0;

      protected:

      	float myValue;
	};
};

#endif
