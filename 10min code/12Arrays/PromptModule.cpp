#include <iostream>

#include "PromptModule.h"

namespace SAMSPrompt
{
   using namespace std;

   bool UserWantsToContinueYorN(const char *theThingWeAreDoing)
   {
      char DoneCharacter;
      bool InvalidCharacterWasEntered = false;

      do
      {
         cout <<
            endl <<
            theThingWeAreDoing <<
            " - Press \"n\" and \"Enter\" to stop: ";

         cin >> DoneCharacter;

			InvalidCharacterWasEntered =         	!
            (
               (DoneCharacter == 'y')
               ||
               (DoneCharacter == 'n')
            );

			if (InvalidCharacterWasEntered)
         {
             cout << "... Error - please enter \"y\" or \"n\"." << endl;
         };
      }
      while (InvalidCharacterWasEntered);

      return (DoneCharacter != 'n'); // Returns true when character is not "n"
   }

   void PauseForUserAcknowledgement(void)
   {
      // Note: You must enter something - just the Enter key is not enough
      char ContinueCharacter;
      cout << endl << "Press some key and \"Enter\" to terminate the program: ";
      cin >> ContinueCharacter;
   }

   bool UserWantsToContinue(const char *theThingWeAreDoing)
   {
      char DoneCharacter;

      cout <<
         endl <<
         theThingWeAreDoing <<
         " - Press \"n\" and \"Enter\" to stop: ";

      cin >> DoneCharacter;

      return (DoneCharacter != 'n'); // Returns true when character is not "n"
   }
}