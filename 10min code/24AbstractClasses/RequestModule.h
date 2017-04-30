#ifndef RequestModuleH
#define RequestModuleH

namespace SAMSCalculator
{


	class aRequest
   {
   	public:

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

         // Note: There is no default constructor - you must provide an
         // operator and operand when creating an instance of this class

         aRequest(const anOperator theOperator,const float anOperand);

         // Allow a copy

         aRequest(const aRequest &theOtherRequest);

         // Support assignment

         aRequest &operator =(const aRequest &theOtherRequest);

         // These functions can be called without an instance

			static char OperatorAsCharacter(const anOperator theOperator);
         static anOperator CharacterAsOperator(const char theCharacter);

         // You cannot change the operator or operand after an instance
         // of this class is created; you can only get their values

         anOperator Operator(void) const;
         char OperatorCharacter(void) const;

         float Operand(void) const;

      private:

      	anOperator myOperator;
         float myOperand;
	};
};

#endif
