#ifndef TransientTapeModuleH
#define TransientTapeModuleH

#include <vector>

#include "RequestModule.h"
#include "TapeModule.h"

namespace SAMSCalculator
{
	class aTransientTape: public aTape
   {
   	public:

      	aTransientTape(void);
         virtual ~aTransientTape(void);

         void Add(const aRequest &theRequest);

         int NumberOfElements(void) const;
         aRequest Element(const int theElementIndex) const; // Returns a copy

      private:

      	std::vector<aRequest> myTape;

         bool Recordable(const aRequest &theRequest) const;
   };
};

#endif
