# Makefile
CC = g++
CCFLAGS = -g

STL-lab: main.o
	$(CC) $(CCFLAGS) -o STL-lab main.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<