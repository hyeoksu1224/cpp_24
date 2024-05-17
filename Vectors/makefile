# Makefile
CC = g++
CCFLAGS = -g

Avector: Amain.o Avector.o Kvector.o
	$(CC) $(CCFLAGS) -o Avector Amain.o Avector.o Kvector.o

BitSet: main.o BitSet.o Bvector.o Kvector.o
	$(CC) $(CCFLAGS) -o BitSet main.o BitSet.o Bvector.o Kvector.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<