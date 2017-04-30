#ifndef ConsoleOnlyExternalInterfaceModuleH
#define ConsoleOnlyExternalInterfaceModuleH

#include "RequestModule.h"
#include "ExternalInterfaceModule.h"

namespace SAMSCalculator
{
	class aConsoleOnlyExternalInterface: public anExternalInterface
   {
   	public:

      	aConsoleOnlyExternalInterface(void);

      	aRequest NextRequest(void) const;

         aConsoleOnlyExternalInterface &operator << (const char *theText) const;
         aConsoleOnlyExternalInterface &operator << (const float theNumber) const;
         aConsoleOnlyExternalInterface &operator << (const aRequest &theRequest) const;

         void DisplayEndOfLine(void) const;

         char OperatorAsCharacter(aRequest::anOperator theOperator) const;
         
      protected:

   		char GetOperatorChar(void);
         float GetOperand(void);

      private:

         bool OperatorNeedsAnOperand(aRequest::anOperator theOperator) const;
         aRequest::anOperator GetOperator(void) const;

         void Display(const char *theText) const;
         void Display(const aRequest &theRequest) const;
         void Display(const float theNumber) const;
	};
};

#endif
