# Makefile - MonteCarloSimulation

.PHONY: all
all: test doc

.PHONY: test
test:
	g++ -c ./src/ComplexNumbers.cpp -o ./test/complex.o -std=c++11 &&\
	g++ -c ./src/InputParser.cpp -o ./test/parser.o -std=c++11 &&\
	g++ -c ./src/MonteCarloSimulator.cpp -o ./test/msc.o -std=c++11 &&\
	cd test/ && g++ complex.o parser.o msc.o main.cpp -o MonteCarloSimulator.o -std=c++11 &&\
	./MonteCarloSimulator.o -o output.txt && cd ..

.PHONY: clean
clean:
	cd test/ && rm complex.o && rm msc.o && rm parser.o && rm MonteCarloSimulator.o && rm output.txt &&\
	rm -rf -- ../doc/html && rm -rf -- ../doc/latex && rm -rf --  && cd ..

.PHONY: doc
doc: 
	doxygen ./doc/MonteCarloSimulation.config

