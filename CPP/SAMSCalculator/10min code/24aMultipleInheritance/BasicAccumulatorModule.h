#ifndef BasicAccumulatorModuleH
#define BasicAccumulatorModuleH

#include "AccumulatorModule.h"
#include "InstanceCountableModule.h"

namespace SAMSCalculator
{
	class aBasicAccumulator: public anAccumulator, public isInstanceCountable
   {
   	public:

      	aBasicAccumulator(void);
         aBasicAccumulator(aBasicAccumulator &theAccumulator);

         float Apply(const aRequest &theRequest);
         float Value(void) const;

         anAccumulator &ReferenceToANewAccumulator(void);
	};
};

#endif
