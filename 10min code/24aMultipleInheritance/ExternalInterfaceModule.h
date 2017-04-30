#ifndef ExternalInterfaceModuleH
#define ExternalInterfaceModuleH

#include "RequestModule.h"

namespace SAMSCalculator
{
	class anExternalInterface
   {
      public:

      	virtual aRequest NextRequest(void) const = 0;

         virtual anExternalInterface &operator << (const char *theText) const = 0;
         virtual anExternalInterface &operator << (const float theNumber) const = 0;
         virtual anExternalInterface &operator << (const aRequest &theRequest) const = 0;

         virtual void DisplayEndOfLine(void) const = 0;

         virtual char OperatorAsCharacter(aRequest::anOperator theOperator) const = 0;

      protected:

   		virtual char GetOperatorChar(void) = 0;
         virtual float GetOperand(void) = 0;
	};
};

#endif
