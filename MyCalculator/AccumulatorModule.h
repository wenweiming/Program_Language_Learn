#ifndef AccumulatorModuleH
#define AccumulatorModuleH

namespace SAMSCalculator
{
	class anAccumulator
	{
		public:
			anAccumulator(void);

			anAccumulator(anAccumulator &theAccumulator);

			float Apply(const aRequest &theRequest);

			float Value(void) const;

		private:
			float myValue;

	};
};

#endif	      
