#include <exception>

#include "TransientTapeModule.h"

namespace SAMSCalculator
{
	using namespace std;

	aTransientTape::aTransientTape(void)
   {
   };

   aTransientTape::~aTransientTape(void)
   {
   };

   bool aTransientTape::Recordable(const aRequest &theRequest) const
   {
   	return // true when
      (
      	(theRequest.Operator() == aRequest::add) ||
         (theRequest.Operator() == aRequest::subtract) ||
         (theRequest.Operator() == aRequest::multiply) ||
         (theRequest.Operator() == aRequest::divide) ||
         (theRequest.Operator() == aRequest::reset)
      );
   };

   void aTransientTape::Add(const aRequest &theRequest)
   {
   	if (Recordable(theRequest))
      {
      	myTape.push_back(theRequest); // Makes a copy of the request, adds to end
      };
   };

   int aTransientTape::NumberOfElements(void) const
   {
   	return myTape.size();
   };

   aRequest aTransientTape::Element(const int theElementIndex) const
   {
   	if (theElementIndex < 0)
      {
      	throw
         	runtime_error
            (
               string("SAMSCalculator::aTransientTape::") +
               string("Element") +
               string(" - Received request for element before 0th.")
            );
      }

      if (theElementIndex >= NumberOfElements())
      {
      	throw
         	runtime_error
            (
               string("SAMSCalculator::aTransientTape::") +
               string("OperatorAsCharacter") +
               string(" - Received request for element past end.")
            );
      };

   	return myTape[theElementIndex];
   };
};
