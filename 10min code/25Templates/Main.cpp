#include "ConsoleAndPersistentTapeExternalInterfaceModule.h"
#include "BasicAccumulatorModule.h"
#include "PersistentTapeModule.h"
#include "ControllerModule.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
   SAMSCalculator::aConsoleAndPersistentTapeExternalInterface<float> 	ExternalInterface(argv[1]);
	SAMSCalculator::aBasicAccumulator<float> 										Accumulator;
   SAMSCalculator::aPersistentTape<float> 										Tape(argv[1]);

   SAMSCalculator::aController<float> 												Calculator
   (
   	ExternalInterface,
      Accumulator,
      Tape
   );

	int ReturnCode = Calculator.Operate();

   cout << "Number of instances = " << SAMSCalculator::isInstanceCountable::TotalNumberOfInstances() << endl;
   char Response;
   cin >> Response;

   return ReturnCode;
}

