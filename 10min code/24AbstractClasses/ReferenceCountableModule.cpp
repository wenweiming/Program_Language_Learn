#include "ReferenceCountableModule.h"

namespace SAMSCalculator
{
	int isReferenceCountable::ourInstanceCounter = 0;

   isReferenceCountable::isReferenceCountable(void)
   {
      ourInstanceCounter++;
   };

   isReferenceCountable::~isReferenceCountable(void)
   {
      ourInstanceCounter--;
   };

   int isReferenceCountable::TotalNumberOfInstances(void)
   {
      return ourInstanceCounter;
   };

};
