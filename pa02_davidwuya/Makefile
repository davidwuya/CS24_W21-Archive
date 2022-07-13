CXX_FLAG = --std=c++11 -g -O0 -fsanitize=address

runMovies = runMovies

runMovies: movies.o main.o
	g++ movies.o main.o $(CXXFLAGS) -o runMovies 


movies.o: movies.cpp movies.h
	g++ movies.cpp $(CXXFLAGS) -c

main.o: main.cpp movies.cpp
	g++ main.cpp $(CXXFLAGS) -c
