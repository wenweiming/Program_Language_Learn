#ifndef ControllerModuleH
#define ControllerModuleH

#include "ExternalInterfaceModule.h"
#include "AccumulatorModule.h"
#include "TapeModule.h"
#include "InstanceCountableModule.h"

namespace SAMSCalculator
{
	class aController: public isInstanceCountable
   {
   	public:

      	aController
         (
         	anExternalInterface &theExternalInterface,
            anAccumulator &theAccumulator,
            aTape &theTape
         );

         int Operate(void);

      private:

      	anExternalInterface &myExternalInterface;
         anAccumulator &myAccumulator;
         aTape &myTape;

         bool TestOK
         (
            anAccumulator &theAccumulator,
            const aRequest &theRequest,
            const float theExpectedResult

         ) const;

         void SelfTest(void) const;
         void DisplayAccumulator(void) const;
         void DisplayTape(void) const;
	};
};

#endif
