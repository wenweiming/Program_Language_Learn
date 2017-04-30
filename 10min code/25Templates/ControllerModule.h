#ifndef ControllerModuleH
#define ControllerModuleH

#include <iostream>
#include <exception>

#include "ExternalInterfaceModule.h"
#include "AccumulatorModule.h"
#include "TapeModule.h"
#include "InstanceCountableModule.h"

namespace SAMSCalculator
{
	template <class ofType> class aController: public isInstanceCountable
   {
   	public:

      	aController
         (
         	anExternalInterface<ofType> &theExternalInterface,
            anAccumulator<ofType> &theAccumulator,
            aTape<ofType> &theTape
         );

         int Operate(void);

      private:

      	anExternalInterface<ofType> &myExternalInterface;
         anAccumulator<ofType> &myAccumulator;
         aTape<ofType> &myTape;

         bool TestOK
         (
            anAccumulator<ofType> &theAccumulator,
            const aRequest<ofType> &theRequest,
            const ofType theExpectedResult

         ) const;

         void SelfTest(void) const;
         void DisplayAccumulator(void) const;
         void DisplayTape(void) const;
	};

	using namespace std;

   template <class ofType> aController<ofType>::aController
   (
      anExternalInterface<ofType> &theExternalInterface,
      anAccumulator<ofType> &theAccumulator,
      aTape<ofType> &theTape
   ):
      myExternalInterface(theExternalInterface),
      myAccumulator(theAccumulator),
      myTape(theTape)
   {
   };

   template <class ofType> bool aController<ofType>::TestOK
   (
   	anAccumulator<ofType> &theAccumulator,
      const aRequest<ofType> &theRequest,
      const ofType theExpectedResult

   ) const
   {
   	ofType AccumulatorValue = theAccumulator.Apply(theRequest);
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

	template <class ofType> void aController<ofType>::SelfTest(void) const
   {
   	anAccumulator<ofType> &TestAccumulator = myAccumulator.ReferenceToANewAccumulator();

      try
      {
         if
            (
               TestOK(TestAccumulator,aRequest<ofType>(add,3),3) &&
               TestOK(TestAccumulator,aRequest<ofType>(subtract,2),1) &&
               TestOK(TestAccumulator,aRequest<ofType>(multiply,4),4) &&
               TestOK(TestAccumulator,aRequest<ofType>(divide,2),2)
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

      delete &TestAccumulator;
   };

   template <class ofType> void aController<ofType>::DisplayAccumulator(void) const
   {
      myExternalInterface << myAccumulator.Value();
      myExternalInterface.DisplayEndOfLine();
	};

   template <class ofType> void aController<ofType>::DisplayTape(void) const
   {
   	int NumberOfElements = myTape.NumberOfElements();

      for (int Index = 0; Index < NumberOfElements; Index++)
      {
      	myExternalInterface << myTape.Element(Index);
         myExternalInterface.DisplayEndOfLine();
      };

      DisplayAccumulator();
   };

   template <class ofType> int aController<ofType>::Operate(void)
   {
      bool Done = false;

     	do
      {
      	aRequest<ofType> Request = myExternalInterface.NextRequest();

      	try
         {
            switch (Request.Operator())
            {
               case selftest:

                  SelfTest();
                  break;

               case querytape:

                  DisplayTape();
                  break;

               case query:

                  DisplayAccumulator();
                  break;

               case stop:

               	Done = true;
                  break;

               default:

                  myTape.Add(Request);
                  myAccumulator.Apply(Request);

            };
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
      } while (!Done);

      return 0; // There are no fatal errors that cause a return other than 0
   };

};                      

#endif
