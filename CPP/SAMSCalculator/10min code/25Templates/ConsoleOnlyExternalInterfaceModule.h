#ifndef ConsoleOnlyExternalInterfaceModuleH
#define ConsoleOnlyExternalInterfaceModuleH

#include <iostream>
#include <exception>

#include "RequestModule.h"
#include "ExternalInterfaceModule.h"
#include "InstanceCountableModule.h"

namespace SAMSCalculator
{
	template <class ofType> class aConsoleOnlyExternalInterface: public anExternalInterface<ofType>, public isInstanceCountable
   {
   	public:

      	aConsoleOnlyExternalInterface(void);

      	aRequest<ofType> NextRequest(void) const;

         aConsoleOnlyExternalInterface &operator << (const char *theText) const;
         aConsoleOnlyExternalInterface &operator << (const ofType theNumber) const;
         aConsoleOnlyExternalInterface &operator << (const aRequest<ofType> &theRequest) const;

         void DisplayEndOfLine(void) const;

         char OperatorAsCharacter(anOperator theOperator) const;

      protected:

   		char GetOperatorChar(void);
         ofType GetOperand(void);

      private:

         bool OperatorNeedsAnOperand(anOperator theOperator) const;
         anOperator GetOperator(void);

         void Display(const char *theText) const;
         void Display(const aRequest<ofType> &theRequest) const;
         void Display(const ofType theNumber) const;
	};

	using namespace std;

   template <class ofType> aConsoleOnlyExternalInterface<ofType>::aConsoleOnlyExternalInterface(void)
   {
		cin.exceptions(cin.failbit);
   };

   template <class ofType> char aConsoleOnlyExternalInterface<ofType>::GetOperatorChar(void)
   {
   	char OperatorChar;
      cin >> OperatorChar;
      return OperatorChar;
   };

   template <class ofType> anOperator aConsoleOnlyExternalInterface<ofType>::GetOperator(void)
   {
		return aRequest<ofType>::CharacterAsOperator(GetOperatorChar());
   };

   template <class ofType> ofType aConsoleOnlyExternalInterface<ofType>::GetOperand(void)
   {
   	ofType Operand;

      try
      {
      	cin >> Operand;
      }
      catch (...)
      {
         // Clear the input stream state
      	cin.clear();

         // Get rid of the pending bad characters (up to five)
         char BadOperand[5];
         cin >> BadOperand;

         throw
            runtime_error
            (
               string("SAMSCalculator::aConsoleOnlyExternalInterface<ofType>::") +
               string("GetOperand") +
               string(" - Not a number: ") +
               string(BadOperand)
            );
      };

      return Operand;
   };

   template <class ofType> bool aConsoleOnlyExternalInterface<ofType>::OperatorNeedsAnOperand
   	(anOperator theOperator) const
   {
   	return
      (
      	(theOperator == add) ||
         (theOperator == subtract) ||
         (theOperator == multiply) ||
         (theOperator == divide) ||
         (theOperator == reset)
      );
   };

   template <class ofType> aRequest<ofType> aConsoleOnlyExternalInterface<ofType>::NextRequest(void) const
   {
   	anOperator Operator = GetOperator();

      if (OperatorNeedsAnOperand(Operator))
      {
      	return aRequest<ofType>(Operator,GetOperand());
      }
      else
      {
      	return aRequest<ofType>(Operator,0);
      };
   };

   template <class ofType> void aConsoleOnlyExternalInterface<ofType>::Display(const char *theText) const
   {
   	cout << theText;
   };

   template <class ofType> char aConsoleOnlyExternalInterface<ofType>::OperatorAsCharacter
   	(anOperator theOperator) const
   {
		return aRequest<ofType>::OperatorAsCharacter(theOperator);
	};

   template <class ofType> void aConsoleOnlyExternalInterface<ofType>::Display(const aRequest<ofType> &theRequest) const
   {
   	cout <<
      	OperatorAsCharacter(theRequest.Operator()) <<
         theRequest.Operand();
   };

	template <class ofType> void aConsoleOnlyExternalInterface<ofType>::Display(const ofType theNumber) const
	{
   	cout << theNumber;
   };

   template <class ofType> void aConsoleOnlyExternalInterface<ofType>::DisplayEndOfLine(void) const
   {
   	cout << endl;
   };

   template <class ofType> aConsoleOnlyExternalInterface<ofType> &aConsoleOnlyExternalInterface<ofType>::operator << (const char *theText) const
   {
   	Display(theText);
      return const_cast<aConsoleOnlyExternalInterface<ofType> &>(*this);
   };                                                                             

   template <class ofType> aConsoleOnlyExternalInterface<ofType> &aConsoleOnlyExternalInterface<ofType>::operator << (const ofType theNumber) const
   {
   	Display(theNumber);
      return const_cast<aConsoleOnlyExternalInterface<ofType> &>(*this);
   };

   template <class ofType> aConsoleOnlyExternalInterface<ofType> &aConsoleOnlyExternalInterface<ofType>::operator << (const aRequest<ofType> &theRequest) const
   {
   	Display(theRequest);
      return const_cast<aConsoleOnlyExternalInterface<ofType> &>(*this);
   };
};

#endif
