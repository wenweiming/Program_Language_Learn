#include <iostream>

#include "BasicAccumulatorModule.h"
#include "RequestModule.h"

using namespace std;
using namespace SAMSCalculator;

int main(int argc, char* argv[])
{
   aBasicAccumulator<float>   Accumulator;

   Accumulator.Apply(aRequest<float>(add,3));
   Accumulator.Apply(aRequest<float>(subtract,2));
   Accumulator.Apply(aRequest<float>(multiply,3));
   Accumulator.Apply(aRequest<float>(divide,2));

   cout << "Result = " << Accumulator.Value() << endl;

   char StopCharacter;
   cin >> StopCharacter;

   aBasicAccumulator<int>   IntAccumulator;

   IntAccumulator.Apply(aRequest<int>(add,3));
   IntAccumulator.Apply(aRequest<int>(subtract,2));
   IntAccumulator.Apply(aRequest<int>(multiply,3));
   IntAccumulator.Apply(aRequest<int>(divide,2));

   cout << "Result = " << IntAccumulator.Value() << endl;

   cin >> StopCharacter;

   return 0;
}


