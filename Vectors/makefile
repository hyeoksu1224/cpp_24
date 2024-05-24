# Makefile
CC = g++
CCFLAGS = -g

TemplateClass: main.o Team.o
	$(CC) $(CCFLAGS) -o TemplateClass main.o Team.o

Avector: Amain.o Avector.o Kvector.o
	$(CC) $(CCFLAGS) -o Avector Amain.o Avector.o Kvector.o

BitSet: BitSetMain.o BitSet.o Bvector.o Kvector.o
	$(CC) $(CCFLAGS) -o BitSet BitSetMain.o BitSet.o Bvector.o Kvector.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<