#include<iostream>
#include"PromptModule.h"
namespace SAMSPrompt
{
	using namespace std;
	bool InvalidCharacterWasEntered =false;
	
	void PauseForUserAcknowledgement(void)
	{
		char StopCharacter;
		cout << endl << "Press a key and \"Enter\": ";
		cin >> StopCharacter;
	}

	bool UserWantsToContinue(const char *theThingWeAreDoing)
	{
		char DoneCharacter;
		do
		{
			cout << endl << theThingWeAreDoing << "- Press \"n\" and \"Enter\" to stop: ";
			cin >> DoneCharacter;

			InvalidCharacterWasEntered =
					!
					(
					 (DoneCharacter == 'y')
				 	||	
				 	(DoneCharacter == 'n')
					);
			if (InvalidCharacterWasEntered)
			{
				cout << "...Error -" <<"Please enter \"y\" or \"n\"."<<endl;
			};
		}
		while (InvalidCharacterWasEntered);

		return (DoneCharacter != 'n');
	}
}
