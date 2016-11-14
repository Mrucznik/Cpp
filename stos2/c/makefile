prog: main.o Stack.o
	gcc -Wall -std=c99 -pedantic $^ -o $@

stack.o: Stack.c Stack.h
	gcc -c -Wall -std=c99 -pedantic $< -o $@

main.o: main.c Stack.h
	gcc -c -Wall -std=c99 -pedantic $< -o $@

.PHONY: clean

clean:
	-rm Stack.o main.o progc
