CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec.o llrec-test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

llrec.o: llrec.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@



# Helper I used to test my stack function
st: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) $< -o stack-test

clean:
	rm -f *.o rh llrec-test stack-test *~

.PHONY: clean 