#ifndef ControllerModuleH
#define ControllerModuleH

#include "ExternalInterfaceModule.h"
#include "AccumulatorModule.h"
#include "TapeModule.h"

namespace SAMSCalculator
{
	class aController
	{
		public:
			aController
				(
				 anExternalInterface &theExternalInterface,
				 anAccumulator &theAccumulator,
				 aTape &theTape
				);

			int Operator(void);

		private:
			anExternalInterface &myExternalInterface;
			anAccumulator &myAccumulator;
			aTape &myTape;

			bool TestOk
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
