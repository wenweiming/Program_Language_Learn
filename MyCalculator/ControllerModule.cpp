


namespace SAMSCalculator
{
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

	void aController::SelfTest(void) const
	{
		anAccumulator TestAccumulator;

		try
		{
			if
				(
				 TestOk
				 (
				  TestAccumulator,
				  aRequest(aRequest::add,3),
				  3
				 )
				 &&
				 TestOk
				 (
				  TestAccumulator,
				  aRequest(aRequest::subtract,2),
				  1
				 )
				 &&
				 TestOk
				 (
				  TestAccumulator,
				  aRequest(aRequest::multiply,4),
				  4
				 )
				 &&
				 TestOk
				 (
				  TestAccumulator,
				  aRequest(aRequest::divide,2),
				  2
				 )
				 )
		}
		catch(...)
		{
			cout <<"Test failed because of an exception.";
		};
	};

	void aController::DisplayTape(void) const
	{
		int NumberOfElements = myTape.NumberOfElements();

		for
			(
			 int Index =0;
			 Index < NumberOfElements;
			 Index++
			)
			{
				myExternalInterface.DisplayRequest(myTape.Element(Index));
				myExternalInterface.DisplayEndOfLine();
			};

		DisplayAccumulator();
	};

	int aController::Operate(void)
	{
		aRequest Request = myExternalInterface.NextRequest();

		while (Request.Operator() != aRequest::Stop)
		{
			try 
			{
				switch (Request.Operator())
				{
					case aRequest::Selftest:
						SelfTest;
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
				cerr << "Runtime error: " << RuntimeError.what() <<endl;
			}
			catch (...)
			{
				cerr <<
					"Non runtime_error exception "<<
					"caught in Controller.Operate." <<
					endl;
			};
		};

		return 0;
	};
};
