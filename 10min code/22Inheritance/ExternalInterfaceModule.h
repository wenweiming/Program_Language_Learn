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

         anExternalInterface &operator << (const char *theText) const;
         anExternalInterface &operator << (const float theNumber) const;
         anExternalInterface &operator << (const aRequest &theRequest) const;

         void DisplayEndOfLine(void) const;

         char OperatorAsCharacter(aRequest::anOperator theOperator) const;
         
      protected:

   		virtual char GetOperatorChar(void);
         virtual float GetOperand(void);

      private:

         bool OperatorNeedsAnOperand(aRequest::anOperator theOperator) const;
         aRequest::anOperator GetOperator(void) const;

         void Display(const char *theText) const;
         void Display(const aRequest &theRequest) const;
         void Display(const float theNumber) const;
	};
};

#endif
