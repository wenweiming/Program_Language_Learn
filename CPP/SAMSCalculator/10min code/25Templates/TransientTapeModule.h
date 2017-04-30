#ifndef TransientTapeModuleH
#define TransientTapeModuleH

#include <vector>
#include <exception>

#include "RequestModule.h"
#include "TapeModule.h"
#include "InstanceCountableModule.h"

namespace SAMSCalculator
{
	template <class ofType> class aTransientTape: public aTape<ofType>, public isInstanceCountable
   {
   	public:

      	aTransientTape(void);
         virtual ~aTransientTape(void);

         void Add(const aRequest<ofType> &theRequest);

         int NumberOfElements(void) const;
         aRequest<ofType> Element(const int theElementIndex) const; // Returns a copy

      private:

      	std::vector< aRequest<ofType> > myTape;

         bool Recordable(const aRequest<ofType> &theRequest) const;
   };

	using namespace std;

	template <class ofType> aTransientTape<ofType>::aTransientTape(void)
   {
   };

   template <class ofType> aTransientTape<ofType>::~aTransientTape(void)
   {
   };

   template <class ofType> bool aTransientTape<ofType>::Recordable(const aRequest<ofType> &theRequest) const
   {
   	return // true when
      (
      	(theRequest.Operator() == add) ||
         (theRequest.Operator() == subtract) ||
         (theRequest.Operator() == multiply) ||
         (theRequest.Operator() == divide) ||
         (theRequest.Operator() == reset)
      );
   };

   template <class ofType> void aTransientTape<ofType>::Add(const aRequest<ofType> &theRequest)
   {
   	if (Recordable(theRequest))
      {
      	myTape.push_back(theRequest); // Makes a copy of the request, adds to end
      };
   };

   template <class ofType> int aTransientTape<ofType>::NumberOfElements(void) const
   {
   	return myTape.size();
   };

   template <class ofType> aRequest<ofType> aTransientTape<ofType>::Element(const int theElementIndex) const
   {
   	if (theElementIndex < 0)
      {
      	throw
         	runtime_error
            (
               string("SAMSCalculator::aTransientTape<ofType>::") +
               string("Element") +
               string(" - Received request for element before 0th.")
            );
      }

      if (theElementIndex >= NumberOfElements())
      {
      	throw
         	runtime_error
            (
               string("SAMSCalculator::aTransientTape<ofType>::") +
               string("OperatorAsCharacter") +
               string(" - Received request for element past end.")
            );
      };

   	return myTape[theElementIndex];
   };
};                                       

#endif
