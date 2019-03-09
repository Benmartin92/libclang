CC=g++
INC=-I/usr/lib/llvm-7/include
LLVMLIBDIR = /usr/lib/llvm-7/lib
LDFLAGS = -L$(LLVMLIBDIR)
LDLIBS = -lLLVM-7 -lclang-7

enumparser: enumparser.cpp
	$(CC) $(INC) -o enumparser enumparser.cpp $(LDFLAGS) $(LDLIBS)


all: enumparser
