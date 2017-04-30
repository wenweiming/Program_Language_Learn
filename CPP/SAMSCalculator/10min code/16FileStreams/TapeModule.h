#ifndef TapeModuleH
#define TapeModuleH

namespace SAMSCalculator
{
   void Tape
   (
      const char theOperator,
      const float theOperand = 0,
      const char *theTapeOutputStreamName = NULL
   );
}

#endif
