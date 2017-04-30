#ifndef ConsoleAndPersistentTapeExternalInterfaceModuleH
#define ConsoleAndPersistentTapeExternalInterfaceModuleH

#include <fstream>
#include "ConsoleOnlyExternalInterfaceModule.h"

namespace SAMSCalculator
{
	using namespace std;

   template <class ofType> class aConsoleAndPersistentTapeExternalInterface: public aConsoleOnlyExternalInterface<ofType>
   {
   	public:

			aConsoleAndPersistentTapeExternalInterface(void);
         aConsoleAndPersistentTapeExternalInterface(const char *theTapeSourceFilePath);

      protected:

      	// These functions cannot be const or ifstream cannot use >>
   		char GetOperatorChar(void);
      	ofType GetOperand(void);

      private:

      	ifstream myTapeSourceInputStream;
   };

	using namespace std;

   template <class ofType> aConsoleAndPersistentTapeExternalInterface<ofType>::aConsoleAndPersistentTapeExternalInterface(void)
   {
      throw
         runtime_error
         (
            string("The default constructor for aConsoleAndPersistentTapeExternalInterface has been used. ") +
            string("Use only the constructor that requires the file path.")
         );
   };

   template <class ofType> aConsoleAndPersistentTapeExternalInterface<ofType>::aConsoleAndPersistentTapeExternalInterface(const char *theTapeSourceFilePath)
   {
   	if (theTapeSourceFilePath != "")
      {
      	myTapeSourceInputStream.open(theTapeSourceFilePath,ifstream::in);
      };
   };

   template <class ofType> char aConsoleAndPersistentTapeExternalInterface<ofType>::GetOperatorChar(void)
   {
   	if (myTapeSourceInputStream.is_open() && !myTapeSourceInputStream.eof())
      {
      	char OperatorChar;
      	myTapeSourceInputStream >> OperatorChar;

         if (OperatorChar == '\0') // The file is empty
         {
            myTapeSourceInputStream.close();
            return aConsoleOnlyExternalInterface<ofType>::GetOperatorChar();
      	}
         else
         {
         	return OperatorChar;
         };
      }
      else
      {
      	if (myTapeSourceInputStream.is_open()) myTapeSourceInputStream.close();
      	return aConsoleOnlyExternalInterface<ofType>::GetOperatorChar();
      };
   };

   template <class ofType> ofType aConsoleAndPersistentTapeExternalInterface<ofType>::GetOperand(void)
   {
   	if (myTapeSourceInputStream.is_open() && !myTapeSourceInputStream.eof())
      {
      	ofType Operand;
      	myTapeSourceInputStream >> Operand;
         return Operand;
      }
      else
      {
      	if (myTapeSourceInputStream.is_open()) myTapeSourceInputStream.close();
      	return aConsoleOnlyExternalInterface<ofType>::GetOperand();
      };
   };

};
                                                                                             
#endif
