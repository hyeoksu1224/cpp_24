# Makefile
CC = g++
CCFLAGS = -g

String: main.o
	$(CC) $(CCFLAGS) -o String main.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<