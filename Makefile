CXX = g++

CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = cipher.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^


