#include <iostream>
#include <exception>

#include "ControllerModule.h"

namespace SAMSCalculator
{
	using namespace std;

   aController::aController
   (
      anExternalInterface &theExternalInterface,
      anAccumulator &theAccumulator,
      aTape &theTape
   ):
      myExternalInterface(theExternalInterface),
      myAccumulator(theAccumulator),
      myTape(theTape)
   {
   };

   bool aController::TestOK
   (
   	anAccumulator &theAccumulator,
      const aRequest &theRequest,
      const float theExpectedResult

   ) const
   {
   	float AccumulatorValue = theAccumulator.Apply(theRequest);
   	bool TestResult = (AccumulatorValue == theExpectedResult);
      const bool OK = true;

      if (TestResult == OK)
      {
      	cout <<
         	myExternalInterface.OperatorAsCharacter(theRequest.Operator()) <<
            " - OK."<<
         	endl;
      }
      else
      {
      	cout <<
         	myExternalInterface.OperatorAsCharacter(theRequest.Operator()) <<
            " - failed. " <<
            "Expected " << theExpectedResult <<
            ", received " << AccumulatorValue << "." <<
         	endl;
      };

      return TestResult;
   };

	void aController::SelfTest(void) const
   {
   	anAccumulator TestAccumulator;

      try
      {
         if
            (
               TestOK
               (
               	TestAccumulator,
                  aRequest(aRequest::add,3),
               	3
               )
               &&
               TestOK
               (
               	TestAccumulator,
                  aRequest(aRequest::subtract,2),
                  1
               )
               &&
               TestOK
               (
               	TestAccumulator,
                  aRequest(aRequest::multiply,4),
                  4
               )
               &&
               TestOK
               (
               	TestAccumulator,
                  aRequest(aRequest::divide,2),
                  2
               )
            )
         {
            cout << "Test OK." << endl;
         }
         else
         {
         	cout << "Test failed." << endl;
         };
      }
      catch (...)
      {
      	cout << "Test failed because of an exception.";
      };
   };

   void aController::DisplayAccumulator(void) const
   {
      myExternalInterface.DisplayNumber(myAccumulator.Value());
      myExternalInterface.DisplayEndOfLine();
	};

   void aController::DisplayTape(void) const
   {
   	int NumberOfElements = myTape.NumberOfElements();

      for (int Index = 0; Index < NumberOfElements; Index++)
      {
      	myExternalInterface.DisplayRequest(myTape.Element(Index));
         myExternalInterface.DisplayEndOfLine();
      };

      DisplayAccumulator();
   };

   int aController::Operate(void)
   {
   	aRequest Request = myExternalInterface.NextRequest();

   	while (Request.Operator() != aRequest::stop)
      {
      	try
         {
            switch (Request.Operator())
            {
               case aRequest::selftest:

                  SelfTest();
                  break;

               case aRequest::querytape:

                  DisplayTape();
                  break;

               case aRequest::query:

                  DisplayAccumulator();
                  break;

               default:

                  myTape.Add(Request);
                  myAccumulator.Apply(Request);

            };

      		Request = myExternalInterface.NextRequest();
         }
         catch (runtime_error RuntimeError)
         {
         	cerr << "Runtime error: " << RuntimeError.what() << endl;
         }
         catch (...)
         {
         	cerr <<
            	"Non runtime_error exception caught in Controller.Operate." <<
               endl;
         };
      };

      return 0; // There are no fatal errors that cause a return other than 0
   };
};

