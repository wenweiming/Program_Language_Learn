#include<exception>
#include<fstream>

#ifndef ErrorHandlingModuleH
#define ErrorHandlingModuleH


namespace SAMSErrorHandling
{
	using namespace std;
	void Initialize(void);
	int HandleNotANumberError(void);
	int HandleRuntimeError(runtime_error theRuntimeError);
	int HandleInputStreamError(ifstream &theStream,ios_base::failure &theIOError);
	int HandleOutputStreamError(ofstream &theStream,ios_base::failure &theIOError);
}

#endif
