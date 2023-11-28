all: bin/functionalTests

# --------------------------------------------------

bin/Model.o: src/Model.cpp
	@g++ -c -o bin/Model.o src/Model.cpp -Wall

bin/System.o: src/System.cpp
	@g++ -c -o bin/System.o src/System.cpp -Wall

bin/Flow.o: src/Flow.cpp
	@g++ -c -o bin/Flow.o src/Flow.cpp -Wall

# --------------------------------------------------

bin/functionalTests: bin/mainFunctional.o bin/functionalTests.o bin/System.o bin/Flow.o bin/Model.o
	@g++ -Wall -lm -o bin/functionalTests bin/mainFunctional.o bin/functionalTests.o bin/System.o bin/Flow.o bin/Model.o

bin/mainFunctional.o: test/functional/mainFunctional.cpp
	@g++ -c -o bin/mainFunctional.o test/functional/mainFunctional.cpp -Wall

bin/functionalTests.o: test/functional/functionalTests.cpp
	@g++ -c -o bin/functionalTests.o test/functional/functionalTests.cpp -Wall
