CXX = g++

CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = cipher.o test.o

main: test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^


