# Makefile
CC = g++
CCFLAGS = -g

NameSpace: main.o
	$(CC) $(CCFLAGS) -o NameSpace main.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<