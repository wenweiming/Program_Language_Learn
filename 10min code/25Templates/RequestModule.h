#ifndef RequestModuleH
#define RequestModuleH

#include <exception>
#include "InstanceCountableModule.h"

namespace SAMSCalculator
{
   enum anOperator
   {
      add,
      subtract,
      multiply,
      divide,
      query,
      reset,
      selftest,
      querytape,
      stop
   };

	template <class ofType> class aRequest:
   	public isInstanceCountable
   {
   	public:

   		// Note: There is no default constructor -
         // you must provide an perator and operand when
         // creating an instance of this class

         aRequest
         (
         	const anOperator theOperator,
            const ofType anOperand
         );

         // Allow a copy

         aRequest(const aRequest &theOtherRequest);

         // Support assignment

         aRequest &operator =
         	(const aRequest &theOtherRequest);

         // These can be called without an instance:

			static char OperatorAsCharacter
         	(const anOperator theOperator);

         static anOperator CharacterAsOperator
         	(const char theCharacter);

         // You cannot change the operator or operand after an instance
         // of this class is created; you can only get their values

         anOperator Operator(void) const;
         char OperatorCharacter(void) const;

         ofType Operand(void) const;

      private:

      	anOperator myOperator;
         ofType myOperand;
	};

	using namespace std;

   template <class ofType> aRequest<ofType>::aRequest
   (
   	const anOperator theOperator,
      const ofType theOperand
   ):
      myOperator(theOperator),
      myOperand(theOperand)
   {
   };

   template <class ofType> aRequest<ofType>::aRequest
   	(const aRequest &theRequest):
      	myOperator(theRequest.myOperator),
      	myOperand(theRequest.myOperand)
   {
   };

   template <class ofType>
   	aRequest<ofType> &aRequest<ofType>::operator =
      	(const aRequest &theRequest)
   {
   	myOperator = theRequest.myOperator;
      myOperand = theRequest.myOperand;

      return *this;
   };

   template <class ofType>
   	char aRequest<ofType>::OperatorAsCharacter
      	(const anOperator theOperator)
   {
      switch (theOperator)
      {
      	case add: 			return '+';
         case subtract: 	return '-';
         case multiply: 	return '*';
         case divide: 		return '/';
         case query: 		return '=';
         case reset: 		return '@';
         case querytape: 	return '?';
         case selftest: 	return '!';

         default:

         	throw
            	runtime_error
               (
               	string("SAMSCalculator::") +
                  string("aRequest<ofType>::") +
                  string("OperatorAsCharacter") +
                  string(" - Unknown operator ") +
                  string("to be translated.")
               );
      };
   };

   template <class ofType>
   	anOperator aRequest<ofType>::CharacterAsOperator
      	(const char theCharacter)
   {
      switch (theCharacter)
      {
      	case '+': return add;
         case '-': return subtract;
         case '*': return multiply;
         case '/': return divide;
         case '=': return query;
         case '@': return reset;
         case '?': return querytape;
         case '!': return selftest;
         case '.': return stop;

         default:

         	char OperatorCharAsString[2];
            OperatorCharAsString[0] = theCharacter;
            OperatorCharAsString[1] = '\0';

         	throw
            	runtime_error
               (
               	string("SAMSCalculator::") +
                  string("aRequest<ofType>::") +
                  string("OperatorAsCharacter") +
                  string(" - Unknown operator char: ") +
                  string(OperatorCharAsString)
               );
      };
   };

   template <class ofType>
   	anOperator aRequest<ofType>::Operator(void) const
   {
      return myOperator;
   };

	template <class ofType>
   	char aRequest<ofType>::OperatorCharacter(void) const
   {
   	return OperatorAsCharacter(myOperator);
   };

   template <class ofType>
   	ofType aRequest<ofType>::Operand(void) const
   {
      return myOperand;
   };
};

#endif
