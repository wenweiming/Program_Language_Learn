#ifndef TapeModuleH
#define TapeModuleH

#include "RequestModule.h"

namespace SAMSCalculator
{
	class aTape
   {
   	public:

      	aTape(void);
         virtual ~aTape(void);

         virtual void Add(const aRequest &theRequest) = 0;

         virtual int NumberOfElements(void) const = 0;
         virtual aRequest Element(const int theElementIndex) const = 0; // Returns a copy
   };
};

#endif
