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

   char anExternalInterface::GetOperatorChar(void) const
   {
   	char OperatorChar;
      cin >> OperatorChar;
      return OperatorChar;
   };

   aRequest::anOperator anExternalInterface::GetOperator
   	(void) const
   {
   	char OperatorChar = GetOperatorChar();

      switch (OperatorChar)
      {
      	case '+': return aRequest::add;
         case '-': return aRequest::subtract;
         case '*': return aRequest::multiply;
         case '/': return aRequest::divide;
         case '=': return aRequest::query;
         case '@': return aRequest::reset;
         case '?': return aRequest::querytape;
         case '!': return aRequest::selftest;
         case '.': return aRequest::stop;

         default:

         	char OperatorCharAsString[2];
            OperatorCharAsString[0] = OperatorChar;
            OperatorCharAsString[1] = '\0';

         	throw
            	runtime_error
               (
                  string("SAMSCalculator::") +
                  string("anExternalInterface::") +
                  string("GetOperator") +
                  string(" - Unknown operator: ") +
                  string(OperatorCharAsString)
               );
      };
   };

   float anExternalInterface::GetOperand(void) const
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

         // Get rid of the pending bad characters
         char BadOperand[5];
         cin >> BadOperand;

         throw
            runtime_error
            (
               string("SAMSCalculator::") +
               string("anExternalInterface::") +
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

   void anExternalInterface::DisplayText
      (const char *theText) const
   {
   	cout << theText;
   };

   char anExternalInterface::OperatorAsCharacter
   	(aRequest::anOperator theOperator) const
   {
      switch (theOperator)
      {
      	case aRequest::add: 			return '+';
         case aRequest::subtract: 	return '-';
         case aRequest::multiply: 	return '*';
         case aRequest::divide: 		return '/';
         case aRequest::query: 		return '=';
         case aRequest::reset: 		return '@';
         case aRequest::querytape: 	return '?';
         case aRequest::selftest: 	return '!';

         default:

         	throw
            	runtime_error
               (
               	string("SAMSCalculator::anExternalInterface::") +
                  string("OperatorAsCharacter") +
                  string(" - Unknown operator to be translated.")
               );
      };
	};

   void anExternalInterface::DisplayRequest(const aRequest &theRequest) const
   {
   	cout <<
      	OperatorAsCharacter(theRequest.Operator()) <<
         theRequest.Operand();
   };

	void anExternalInterface::DisplayNumber(const float theNumber) const
	{
   	cout << theNumber;
   };

   void anExternalInterface::DisplayEndOfLine(void) const
   {
   	cout << endl;
   };                                                                  
};
