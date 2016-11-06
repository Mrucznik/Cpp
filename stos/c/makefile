prog: main.o Stack.o
	gcc -Wall -pedantic $^ -o $@

stack.o: Stack.c Stack.h
	gcc -c -Wall -pedantic $< -o $@

main.o: main.c Stack.h
	gcc -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm Stack.o main.o prog
