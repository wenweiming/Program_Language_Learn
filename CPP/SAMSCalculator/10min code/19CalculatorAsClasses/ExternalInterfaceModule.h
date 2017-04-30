#ifndef ExternalInterfaceModuleH
#define ExternalInterfaceModuleH

#include "RequestModule.h"

namespace SAMSCalculator
{
	class anExternalInterface
   {
   	public:

      	anExternalInterface(void);

      	aRequest NextRequest(void) const;

         void DisplayText(const char *theText) const;
         void DisplayRequest(const aRequest &theRequest) const;
         void DisplayNumber(const float theNumber) const;
         void DisplayEndOfLine(void) const;

         char OperatorAsCharacter(aRequest::anOperator theOperator) const;
         
      private:

   		char GetOperatorChar(void) const;
         aRequest::anOperator GetOperator(void) const;

         bool OperatorNeedsAnOperand(aRequest::anOperator theOperator) const;

         float GetOperand(void) const;
	};
};

#endif
