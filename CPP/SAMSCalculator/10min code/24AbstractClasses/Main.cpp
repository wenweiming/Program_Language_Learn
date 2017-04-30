#include "ConsoleAndPersistentTapeExternalInterfaceModule.h"
#include "BasicAccumulatorModule.h"
#include "PersistentTapeModule.h"
#include "ControllerModule.h"

int main(int argc, char* argv[])
{
   SAMSCalculator::aConsoleAndPersistentTapeExternalInterface 	ExternalInterface(argv[1]);
	SAMSCalculator::aBasicAccumulator 						Accumulator;
   SAMSCalculator::aPersistentTape 							Tape(argv[1]);

   SAMSCalculator::aController 								Calculator
   (
   	ExternalInterface,
      Accumulator,
      Tape
   );

	return Calculator.Operate();
}

