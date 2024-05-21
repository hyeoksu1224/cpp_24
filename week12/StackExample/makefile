# Makefile
CC = g++
CCFLAGS = -g

myStack: myStack.o
	$(CC) $(CCFLAGS) -o myStack myStack.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<