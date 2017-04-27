#ifndef ExternalInterfaceModuleH
#define ExternalInterfaceModuleH

#include "RequestModule.h"

namespace SAMSCalculator
{
	template <class ofType> class anExternalInterface
   {
      public:

      	virtual aRequest<ofType> NextRequest(void) const = 0;

         virtual anExternalInterface &operator << (const char *theText) const = 0;
         virtual anExternalInterface &operator << (const ofType theNumber) const = 0;
         virtual anExternalInterface &operator << (const aRequest<ofType> &theRequest) const = 0;

         virtual void DisplayEndOfLine(void) const = 0;

         virtual char OperatorAsCharacter(anOperator theOperator) const = 0;

      protected:

   		virtual char GetOperatorChar(void) = 0;
         virtual ofType GetOperand(void) = 0;
	};
};

#endif
