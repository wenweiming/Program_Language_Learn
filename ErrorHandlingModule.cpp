#include<iostream>
#include"ErrorHandlingModule.h"

namespace SAMSErrorHandling
{
	using namespace std;

	void Initialize(void)
	{
		cin.exceptions(cin.failbit);
	}

	int HandleNotANumberError(void)
	{
		cerr << "Input error - input may not have been a number." <<endl;
		cin.clear();
		char BadInput[5];
		cin >> BadInput;
	
		return 1;
	}
}
