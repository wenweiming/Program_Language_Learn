#ifndef AccumulatorModuleH
#define AccumulatorModuleH

#include "RequestModule.h"

namespace SAMSCalculator
{
	template <class ofType> class anAccumulator
   {
   	public:

      	anAccumulator(void);
         anAccumulator(anAccumulator &theAccumulator);

         virtual ~anAccumulator(void);

         virtual ofType Apply
         	(const aRequest<ofType> &theRequest) = 0;

         virtual ofType Value(void) const = 0;

         virtual anAccumulator
         	&ReferenceToANewAccumulator(void) = 0;

      protected:

      	ofType myValue;
	};

   using namespace std;

   template <class ofType>
   	anAccumulator<ofType>::anAccumulator(void):
      	myValue(0)
   {
   };

   template <class ofType>
   	anAccumulator<ofType>::anAccumulator
      	(anAccumulator &theAccumulator):
   			myValue(theAccumulator.myValue)
   {
   };

   template <class ofType>
   	anAccumulator<ofType>::~anAccumulator(void)
   {
   };

};

#endif
