#include "InstanceCountableModule.h"

namespace SAMSCalculator
{
	int isInstanceCountable::ourInstanceCounter = 0;

   isInstanceCountable::isInstanceCountable(void)
   {
      ourInstanceCounter++;
   };

   isInstanceCountable::~isInstanceCountable(void)
   {
      ourInstanceCounter--;
   };

   int isInstanceCountable::TotalNumberOfInstances(void)
   {
      return ourInstanceCounter;
   };

};
