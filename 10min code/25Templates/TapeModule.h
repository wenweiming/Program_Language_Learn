#ifndef TapeModuleH
#define TapeModuleH

#include "RequestModule.h"

namespace SAMSCalculator
{
	template <class ofType> class aTape
   {
   	public:

      	aTape(void);
         virtual ~aTape(void);

         virtual void Add(const aRequest<ofType> &theRequest) = 0;

         virtual int NumberOfElements(void) const = 0;
         virtual aRequest<ofType> Element(const int theElementIndex) const = 0; // Returns a copy
   };

	template <class ofType> aTape<ofType>::aTape(void)
   {
   };

   template <class ofType> aTape<ofType>::~aTape(void)
   {
   };
};

#endif
