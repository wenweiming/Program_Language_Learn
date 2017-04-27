#include <exception>

#ifndef ErrorHandlingModuleH
#define ErrorHandlingModuleH

namespace SAMSErrorHandling
{
	using namespace std;

	void Initialize(void);
	int HandleNotANumberError(void); // Returns the error code
   int HandleRuntimeError(runtime_error theRuntimeError);
}

#endif
