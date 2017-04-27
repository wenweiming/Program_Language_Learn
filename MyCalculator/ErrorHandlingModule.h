#ifndef ErrorHandlingModuleH
#define ErrorHandlingModuleH

#include<exception>
using namespace std;

namespace SAMSErrorHandling
{
	void Initialize(void);
	int HandleNotANumberError(void);
	int HandleRuntimeError(runtime_error theRuntimeError);
}

#endif
