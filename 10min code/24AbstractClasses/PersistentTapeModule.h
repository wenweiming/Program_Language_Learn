#ifndef PersistentTapeModuleH
#define PersistentTapeModuleH

#include <string>

#include "TransientTapeModule.h"

namespace SAMSCalculator
{
	class aPersistentTape: public aTransientTape
   {
   	public:

      	aPersistentTape(void);
         aPersistentTape(const char *theOutputFilePath);

         ~aPersistentTape(void);

      private:

         std::string myOutputFilePath;
   };
};

#endif
