try: PromptModule.o ErrorHandlingModule.o Main.o AccumulatorModule.o ExternalInterfaceModule.o TapeModule.o 
	g++  PromptModule.o ErrorHandlingModule.o Main.o AccumulatorModule.o ExternalInterfaceModule.o TapeModule.o -o try

Main.o: Main.cpp
	g++ -c -g Main.cpp

PromptModule.o: PromptModule.cpp PromptModule.h
	g++ -c -g PromptModule.cpp

ErrorHandlingModule.o: ErrorHandlingModule.cpp ErrorHandlingModule.h
	g++ -c -g ErrorHandlingModule.cpp

AccumulatorModule.o: AccumulatorModule.cpp AccumulatorModule.h
	g++ -c -g AccumulatorModule.cpp

TapeModule.o: TapeModule.h TapeModule.cpp
	g++ -c -g TapeModule.cpp

ExternalInterfaceModule.o: ExternalInterfaceModule.cpp ExternalInterfaceModule.h
	g++ -c -g ExternalInterfaceModule.cpp
clean:
	rm *.o
