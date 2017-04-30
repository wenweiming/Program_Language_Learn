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

			aRequest
				(
				 const anOperator theOperator
				 const float theOperand
				);

			aRequest
				(
				 const aRequest &theRequest
				);

			anOperator Operator(void) const;
			float Operand(void) const;

		private:
			anOperator myOperator;
			float myOperand;
	};
};
