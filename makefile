try: PromptModule.o ErrorHandlingModule.o try.o
	g++ -o try PromptModule.o ErrorHandlingModule.o try.o

try.o: try.cpp
	g++ -c try.cpp

PromptModule.o: PromptModule.cpp PromptModule.h
	g++ -c PromptModule.cpp

ErrorHandlingModule.o: ErrorHandlingModule.cpp ErrorHandlingModule.h
	g++ -c ErrorHandlingModule.cpp

clean:
	rm *.o
