#ifndef TapeModuleH
#define TapeModuleH

#include <vector>

#include "RequestModule.h"

namespace SAMSCalculator
{
	class aTape
   {
   	public:

      	aTape(void);
         virtual ~aTape(void);

         void Add(const aRequest &theRequest);

         int NumberOfElements(void) const;
         aRequest Element(const int theElementIndex) const; // Returns a copy

      private:

      	std::vector<aRequest> myTape;

         bool Recordable(const aRequest &theRequest) const;
   };
};

#endif
