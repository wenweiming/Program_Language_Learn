#ifndef PersistentTapeModuleH
#define PersistentTapeModuleH

#include <string>

#include "TapeModule.h"

namespace SAMSCalculator
{
	class aPersistentTape: public aTape
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
