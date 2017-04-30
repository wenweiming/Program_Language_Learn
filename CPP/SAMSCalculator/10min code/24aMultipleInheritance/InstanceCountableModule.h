#ifndef InstanceCountableModuleH
#define InstanceCountableModuleH

namespace SAMSCalculator
{
	class isInstanceCountable
	{
   	public:

      	isInstanceCountable(void);
         ~isInstanceCountable(void);

         static int TotalNumberOfInstances(void);

      private:

      	static int ourInstanceCounter;

   };

};

#endif
