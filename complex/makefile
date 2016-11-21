prog: main.o complex.o
	g++ -g -Wall -pedantic $^ -o $@

complex.o: complex.cpp complex.hpp
	g++ -g -c -Wall -pedantic $< -o $@

main.o: main.cpp complex.hpp
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm complex.o main.o prog
