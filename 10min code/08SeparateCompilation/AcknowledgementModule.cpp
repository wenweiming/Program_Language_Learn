#include <iostream>

#include "AcknowledgementModule.h"

namespace SAMSAcknowledgement
{
   using namespace std;

   void PauseForUserAcknowledgement(void)
   {
      // Note: You must enter something - just the Enter key is not enough
      char StopCharacter;
      cout << endl << "Press some key and \"Enter\" to terminate the program: ";
      cin >> StopCharacter;
   }
}