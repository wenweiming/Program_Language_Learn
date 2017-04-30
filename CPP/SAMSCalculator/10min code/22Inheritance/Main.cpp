#include "PersistentTapeExternalInterfaceModule.h"
#include "AccumulatorModule.h"
#include "PersistentTapeModule.h"
#include "ControllerModule.h"

int main(int argc, char* argv[])
{
   SAMSCalculator::aPersistentTapeExternalInterface 	ExternalInterface(argv[1]);
	SAMSCalculator::anAccumulator 							Accumulator;
   SAMSCalculator::aPersistentTape 							Tape(argv[1]);

   SAMSCalculator::aController 								Calculator
   (
   	ExternalInterface,
      Accumulator,
      Tape
   );

	return Calculator.Operate();
}

