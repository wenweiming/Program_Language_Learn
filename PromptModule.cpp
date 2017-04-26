#include<iostream>
#include"PromptModule.h"
namespace SAMSPrompt
{
	using namespace std;
	
	void PauseForUserAcknowledgement(void)
	{
		char StopCharacter;
		cout << endl << "Press a key and \"Enter\": ";
		cin >> StopCharacter;
	}

	bool UserWantsToContinue(const char *theThingWeAreDoing)
	{
		char DoneCharacter;
		cout << endl << theThingWeAreDoing << "- Press \"n\" and \"Enter\" to stop: ";
		cin >> DoneCharacter;
		return (DoneCharacter != 'n');
	}
}
