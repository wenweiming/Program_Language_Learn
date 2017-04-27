#include "ExternalInterfaceModule.h"
#include "AccumulatorModule.h"
#include "TapeModule.h"
#include "ControllerModule.h"

int main(int argc, char* argv[])
{
   SAMSCalculator::anExternalInterface 	ExternalInterface;
	SAMSCalculator::anAccumulator 			Accumulator;
   SAMSCalculator::aTape 						Tape;

   SAMSCalculator::aController 				Calculator
   (
   	ExternalInterface,
      Accumulator,
      Tape
   );

	return Calculator.Operate();
}

