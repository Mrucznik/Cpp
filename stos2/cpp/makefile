prog: main.o Stack.o
	g++ -g -Wall -pedantic $^ -o $@

stack.o: Stack.cpp Stack.h
	g++ -g -c -Wall -pedantic $< -o $@

main.o: main.cpp Stack.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm Stack.o main.o prog
