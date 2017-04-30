#include <iostream>
#include <exception>

#include "ExternalInterfaceModule.h"

namespace SAMSCalculator
{
	using namespace std;

   anExternalInterface::anExternalInterface(void)
   {
		cin.exceptions(cin.failbit);
   };

   char anExternalInterface::GetOperatorChar(void)
   {
   	char OperatorChar;
      cin >> OperatorChar;
      return OperatorChar;
   };

   aRequest::anOperator anExternalInterface::GetOperator(void) const
   {
		return aRequest::CharacterAsOperator(GetOperatorChar());
   };

   float anExternalInterface::GetOperand(void)
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
               string("SAMSCalculator::anExternalInterface::") +
               string("GetOperand") +
               string(" - Not a number: ") +
               string(BadOperand)
            );
      };

      return Operand;
   };

   bool anExternalInterface::OperatorNeedsAnOperand
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

   aRequest anExternalInterface::NextRequest(void) const
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

   void anExternalInterface::Display(const char *theText) const
   {
   	cout << theText;
   };

   char anExternalInterface::OperatorAsCharacter
   	(aRequest::anOperator theOperator) const
   {
		return aRequest::OperatorAsCharacter(theOperator);
	};

   void anExternalInterface::Display(const aRequest &theRequest) const
   {
   	cout <<
      	OperatorAsCharacter(theRequest.Operator()) <<
         theRequest.Operand();
   };

	void anExternalInterface::Display(const float theNumber) const
	{
   	cout << theNumber;
   };

   void anExternalInterface::DisplayEndOfLine(void) const
   {
   	cout << endl;
   };

   anExternalInterface &anExternalInterface::operator << (const char *theText) const
   {
   	Display(theText);
      return const_cast<anExternalInterface &>(*this);
   };

   anExternalInterface &anExternalInterface::operator << (const float theNumber) const
   {
   	Display(theNumber);
      return const_cast<anExternalInterface &>(*this);
   };

   anExternalInterface &anExternalInterface::operator << (const aRequest &theRequest) const
   {
   	Display(theRequest);
      return const_cast<anExternalInterface &>(*this);
   };
};
