#include <exception>

#include "TapeModule.h"

namespace SAMSCalculator
{
	using namespace std;

   aTape::aTape(void)
   {
   };

   bool aTape::Recordable(const aRequest &theRequest) const
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

   void aTape::Add(const aRequest &theRequest)
   {
   	if (Recordable(theRequest))
      {
      	myTape.push_back(theRequest); // Makes a copy of the request, adds to end
      };
   };

   int aTape::NumberOfElements(void) const
   {
   	return myTape.size();
   };

   aRequest aTape::Element(const int theElementIndex) const
   {
   	if (theElementIndex < 0)
      {
      	throw
         	runtime_error
            (
               string("SAMSCalculator::aTape::") +
               string("Element") +
               string(" - Received request for element before 0th.")
            );
      }

      if (theElementIndex >= NumberOfElements())
      {
      	throw
         	runtime_error
            (
               string("SAMSCalculator::aTape::") +
               string("OperatorAsCharacter") +
               string(" - Received request for element past end.")
            );
      };

   	return myTape[theElementIndex];
   };
};
