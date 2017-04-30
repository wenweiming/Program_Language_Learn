#ifndef ExternalInterfaceModuleH
#define ExternalInterfaceModuleH

namespace SAMSCalculator
{
   typedef char (*ToGetAnOperator)(void);
   typedef float (*ToGetAnOperand)(void);
   typedef void (*ToHandleResults)(const float theResult);
   typedef void (*ToDisplayMessage)(const char *theMessage);

   struct aCalculatorExternalInterface
   {
      ToGetAnOperator GetAnOperator;
      ToGetAnOperand GetAnOperand;
      ToHandleResults HandleResults;
      ToDisplayMessage DisplayMessage;
   };

   int CalculateFromInput
   (
      aCalculatorExternalInterface &theCalculatorExternalInterface
   );
};

#endif
