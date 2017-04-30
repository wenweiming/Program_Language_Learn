#include <iostream>
#include <exception>

#include "ConsoleOnlyExternalInterfaceModule.h"

namespace SAMSCalculator
{
	using namespace std;

   aConsoleOnlyExternalInterface::aConsoleOnlyExternalInterface(void)
   {
		cin.exceptions(cin.failbit);
   };

   char aConsoleOnlyExternalInterface::GetOperatorChar(void)
   {
   	char OperatorChar;
      cin >> OperatorChar;
      return OperatorChar;
   };

   aRequest::anOperator aConsoleOnlyExternalInterface::GetOperator(void) const
   {
		return aRequest::CharacterAsOperator(GetOperatorChar());
   };

   float aConsoleOnlyExternalInterface::GetOperand(void)
   {
   	float Operand;

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
               string("SAMSCalculator::aConsoleOnlyExternalInterface::") +
               string("GetOperand") +
               string(" - Not a number: ") +
               string(BadOperand)
            );
      };

      return Operand;
   };

   bool aConsoleOnlyExternalInterface::OperatorNeedsAnOperand
   	(aRequest::anOperator theOperator) const
   {
   	return
      (
      	(theOperator == aRequest::add) ||
         (theOperator == aRequest::subtract) ||
         (theOperator == aRequest::multiply) ||
         (theOperator == aRequest::divide) ||
         (theOperator == aRequest::reset)
      );
   };

   aRequest aConsoleOnlyExternalInterface::NextRequest(void) const
   {
   	aRequest::anOperator Operator = GetOperator();

      if (OperatorNeedsAnOperand(Operator))
      {
      	return aRequest(Operator,GetOperand());
      }
      else
      {
      	return aRequest(Operator,0);
      };
   };

   void aConsoleOnlyExternalInterface::Display(const char *theText) const
   {
   	cout << theText;
   };

   char aConsoleOnlyExternalInterface::OperatorAsCharacter
   	(aRequest::anOperator theOperator) const
   {
		return aRequest::OperatorAsCharacter(theOperator);
	};

   void aConsoleOnlyExternalInterface::Display(const aRequest &theRequest) const
   {
   	cout <<
      	OperatorAsCharacter(theRequest.Operator()) <<
         theRequest.Operand();
   };

	void aConsoleOnlyExternalInterface::Display(const float theNumber) const
	{
   	cout << theNumber;
   };

   void aConsoleOnlyExternalInterface::DisplayEndOfLine(void) const
   {
   	cout << endl;
   };

   aConsoleOnlyExternalInterface &aConsoleOnlyExternalInterface::operator << (const char *theText) const
   {
   	Display(theText);
      return const_cast<aConsoleOnlyExternalInterface &>(*this);
   };

   aConsoleOnlyExternalInterface &aConsoleOnlyExternalInterface::operator << (const float theNumber) const
   {
   	Display(theNumber);
      return const_cast<aConsoleOnlyExternalInterface &>(*this);
   };

   aConsoleOnlyExternalInterface &aConsoleOnlyExternalInterface::operator << (const aRequest &theRequest) const
   {
   	Display(theRequest);
      return const_cast<aConsoleOnlyExternalInterface &>(*this);
   };
};
