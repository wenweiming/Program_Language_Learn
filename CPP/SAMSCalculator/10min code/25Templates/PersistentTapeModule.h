#ifndef PersistentTapeModuleH
#define PersistentTapeModuleH

#include <fstream>
#include <exception>
#include <string>

#include "TransientTapeModule.h"

namespace SAMSCalculator
{
	template <class ofType> class aPersistentTape: public aTransientTape<ofType>
   {
   	public:

      	aPersistentTape(void);
         aPersistentTape(const char *theOutputFilePath);

         ~aPersistentTape(void);

      private:

         std::string myOutputFilePath;
   };

   template <class ofType> aPersistentTape<ofType>::aPersistentTape(void)
   {
      throw
         runtime_error
         (
            string("The default constructor for aPersistentTape has been used. ") +
            string("Use only the constructor that requires the file path.")
         );
   };

   template <class ofType> aPersistentTape<ofType>::aPersistentTape(const char *theOutputFilePath):
      myOutputFilePath(theOutputFilePath)
   {
   };

   template <class ofType> aPersistentTape<ofType>::~aPersistentTape(void)
   {
   	if (myOutputFilePath.size() > 0)
      {
         ofstream OutputStream(myOutputFilePath.c_str(),ofstream::out);

         int NumberOfTapeElements = NumberOfElements();

         for (int Index = 0; Index < NumberOfTapeElements; Index++)
         {
            OutputStream << Element(Index).OperatorCharacter() << Element(Index).Operand();
         };
      };
   };
                                                    
};

#endif
