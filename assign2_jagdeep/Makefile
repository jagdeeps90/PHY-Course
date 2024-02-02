#Makefile compiles the gameof1dv1 which depends on three modules
# 1.initialize_cells.h and initialize_cells.cpp
# 2.evolution.h and evolution.cpp
# 3.output.h and output.cpp

CXX=g++
CXXFLAGS=-std=c++17
LDFLAGS=-O2

all: gameof1dv1

gameof1dv1: initialize_cells.o evolution.o output.o gameof1dv1.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

gameof1dv1.o: gameof1dv1.cpp initialize_cells.h evolution.h output.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

initialize_cells.o: initialize_cells.cpp initialize_cells.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

evolution.o: evolution.cpp evolution.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

output.o: output.cpp output.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:
	$(RM) initialize_cells.o evolution.o output.o gameof1dv1.o

.PHONY: all clean

