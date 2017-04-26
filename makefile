try: PromptModule.o ErrorHandlingModule.o try.o
	g++  PromptModule.o ErrorHandlingModule.o try.o -o try

try.o: try.cpp
	g++ -c -g try.cpp

PromptModule.o: PromptModule.cpp PromptModule.h
	g++ -c -g PromptModule.cpp

ErrorHandlingModule.o: ErrorHandlingModule.cpp ErrorHandlingModule.h
	g++ -c -g ErrorHandlingModule.cpp

clean:
	rm *.o
