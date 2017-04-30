calculater: AccumulatorModule.o ErrorHandlingModule.o ExternalInterfaceModule.o PromptModule.o TapeModule.o Main.o
	g++ -o calculater AccumulatorModule.o ErrorHandlingModule.o ExternalInterfaceModule.o PromptModule.o Main.o TapeModule.o

TapeModule.o: TapeModule.h TapeModule.cpp
	g++ -g -c TapeModule.cpp

AccumulatorModule.o: AccumulatorModule.h AccumulatorModule.cpp
	g++ -g -c AccumulatorModule.cpp

ErrorHandlingModule.o: ErrorHandlingModule.h ErrorHandlingModule.cpp
	g++ -g -c ErrorHandlingModule.cpp

ExternalInterfaceModule.o: ExternalInterfaceModule.h ExternalInterfaceModule.cpp
	g++ -g -c ExternalInterfaceModule.cpp

PromptModule.o: PromptModule.h PromptModule.cpp
	g++ -g -c PromptModule.cpp

Main.o: Main.cpp
	g++ -g -c Main.cpp

clean:
	rm *.o
