CXX_FLAG = --std=c++11 -g -O0 -fsanitize=address
all: testbst
	./testbst

testbst: testbst.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@