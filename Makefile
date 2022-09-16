CXX = g++

CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = cipher.o password-generator.o test.o

main: test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) main *.o encrypted.txt raw.txt
