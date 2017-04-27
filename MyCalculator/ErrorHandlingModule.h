#ifndef ErrorHandlingModuleH
#define ErrorHandlingModuleH
#include<exception>


namespace SAMSErrorHandling
{
	using namespace std;
	void Initialize(void);
	int HandleNotANumberError(void);
	int HandleRuntimeError(runtime_error theRuntimeError);
}

#endif
