# Makefile
CC = g++
CCFLAGS = -g

exceptionFn: exceptionFn.o
	$(CC) $(CCFLAGS) -o exceptionFn exceptionFn.o

exceptionClass: exceptionClass.o
	$(CC) $(CCFLAGS) -o exceptionClass exceptionClass.o

try-catch: try-catch.o
	$(CC) $(CCFLAGS) -o try-catch try-catch.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<