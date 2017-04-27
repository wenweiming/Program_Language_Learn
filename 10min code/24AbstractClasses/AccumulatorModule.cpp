#include <string>
#include <exception>

#include "AccumulatorModule.h"

namespace SAMSCalculator
{
   using namespace std;

   anAccumulator::anAccumulator(void): myValue(0)
   {
   };

   anAccumulator::anAccumulator(anAccumulator &theAccumulator):
   	myValue(theAccumulator.myValue)
   {
   };

};
