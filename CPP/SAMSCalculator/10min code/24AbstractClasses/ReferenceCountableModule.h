#ifndef ReferenceCountableModuleH
#define ReferenceCountableModuleH

namespace SAMSCalculator
{
	class isReferenceCountable
	{
   	public:

      	isReferenceCountable(void);
         ~isReferenceCountable(void);

         static int TotalNumberOfInstances(void);

      private:

      	static int ourInstanceCounter;

   };

};

#endif
