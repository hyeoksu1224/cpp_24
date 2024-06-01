# Makefile
CC = g++
CCFLAGS = -g

Car: main.o Car.o
	$(CC) $(CCFLAGS) -o Car main.o Car.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<