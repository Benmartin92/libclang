CC=g++
INC=-I/usr/lib/llvm-6.0/include
LLVMLIBDIR = /usr/lib/llvm-6.0/lib
LDFLAGS = -L$(LLVMLIBDIR)
LDLIBS = -lLLVM-6.0

enumparser: enumparser.cpp
	$(CC) $(INC) -o enumparser enumparser.cpp $(LDFLAGS) $(LDLIBS)


