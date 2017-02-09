CXX=g++ 
CXXFLAGS=-g

OBJS = estado.o cinta_t.o TuringMachine.o  main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o TM ${OBJS}

clean: 
	rm -rf *.o TM