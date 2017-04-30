#ifndef ConsoleAndPersistentTapeExternalInterfaceModuleH
#define ConsoleAndPersistentTapeExternalInterfaceModuleH

#include <fstream>
#include "ConsoleOnlyExternalInterfaceModule.h"

namespace SAMSCalculator
{
	using namespace std;

   class aConsoleAndPersistentTapeExternalInterface: public aConsoleOnlyExternalInterface
   {
   	public:

			aConsoleAndPersistentTapeExternalInterface(void);
         aConsoleAndPersistentTapeExternalInterface(const char *theTapeSourceFilePath);

      protected:

      	// These functions cannot be const or ifstream cannot use >>
   		char GetOperatorChar(void);
      	float GetOperand(void);

      private:

      	ifstream myTapeSourceInputStream;
   };
};

#endif
