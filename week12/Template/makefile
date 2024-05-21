# Makefile
CC = g++
CCFLAGS = -g

Template: Template.o
	$(CC) $(CCFLAGS) -o Template Template.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<