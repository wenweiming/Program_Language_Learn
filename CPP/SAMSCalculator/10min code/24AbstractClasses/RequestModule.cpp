#include <iostream>
#include <exception>

#include "RequestModule.h"

namespace SAMSCalculator
{
	using namespace std;

   aRequest::aRequest(const anOperator theOperator,const float theOperand):
      myOperator(theOperator),
      myOperand(theOperand)
   {
   };

   aRequest::aRequest(const aRequest &theRequest):
      myOperator(theRequest.myOperator),
      myOperand(theRequest.myOperand)
   {
   };

   aRequest &aRequest::operator =(const aRequest &theRequest)
   {
   	myOperator = theRequest.myOperator;
      myOperand = theRequest.myOperand;

      return *this;
   };

   char aRequest::OperatorAsCharacter(const anOperator theOperator)
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
               	string("SAMSCalculator::aRequest::") +
                  string("OperatorAsCharacter") +
                  string(" - Unknown operator to be translated.")
               );
      };
   };

   aRequest::anOperator aRequest::CharacterAsOperator(const char theCharacter)
   {
      switch (theCharacter)
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
            OperatorCharAsString[0] = theCharacter;
            OperatorCharAsString[1] = '\0';

         	throw
            	runtime_error
               (
                  string("SAMSCalculator::anExternalInterface::") +
                  string("GetOperator") +
                  string(" - Unknown operator character: ") +
                  string(OperatorCharAsString)
               );
      };
   };

   aRequest::anOperator aRequest::Operator(void) const
   {
      return myOperator;
   };

	char aRequest::OperatorCharacter(void) const
   {
   	return OperatorAsCharacter(myOperator);
   };

   float aRequest::Operand(void) const
   {
      return myOperand;
   };
};
