  
all: out

out: main.o utility_0.o utility_1a.o
	g++ -std=c++11 -O3 -o out main.o utility_0.o utility_1a.o

main.o: main.cpp utility_1a.h 
	g++ -std=c++11 -O3 -g -Wall -fmessage-length=0 -c main.cpp

utility_1a.o: utility_1a.cpp utility_1a.h 
	g++ -std=c++11 -O3 -g -Wall -fmessage-length=0 -c utility_1a.cpp

utility_0.o: utility_0.cpp utility_0.h 
	g++ -std=c++11 -O3 -g -Wall -fmessage-length=0 -c utility_0.cpp

clean:
	rm -f out main.o utility_0.o utility_1a.o