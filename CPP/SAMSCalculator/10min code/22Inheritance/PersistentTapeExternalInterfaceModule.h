#ifndef PersistentTapeExternalInterfaceModuleH
#define PersistentTapeExternalInterfaceModuleH

#include <fstream>
#include "ExternalInterfaceModule.h"

namespace SAMSCalculator
{
	using namespace std;

   class aPersistentTapeExternalInterface: public anExternalInterface
   {
   	public:

			aPersistentTapeExternalInterface(void);
         aPersistentTapeExternalInterface(const char *theTapeSourceFilePath);

      protected:

      	// These functions cannot be const or ifstream cannot use >>
   		char GetOperatorChar(void);
      	float GetOperand(void);

      private:

      	ifstream myTapeSourceInputStream;
   };
};

#endif
