CXX_FLAG = --std=c++11 -g -O0 -fsanitize=address
all: game
	./game

game: main.cpp cards.cpp utility.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@