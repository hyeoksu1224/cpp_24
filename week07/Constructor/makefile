# Makefile
CC = g++
CCFLAGS = -g

A: main.o A.o
	$(CC) $(CCFLAGS) -o A main.o A.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<