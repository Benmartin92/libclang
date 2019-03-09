CXX=g++
CXXFLAGS=-g -std=c++17
INC=-I/usr/lib/llvm-7/include
LLVMLIBDIR = /usr/lib/llvm-7/lib
LDFLAGS = -L$(LLVMLIBDIR)
LDLIBS = -lLLVM-7 -lclang-7

enumparser: enumparser.cpp
	$(CXX) $(CXXFLAGS) $(INC) -o enumparser enumparser.cpp $(LDFLAGS) $(LDLIBS)


all: enumparser
