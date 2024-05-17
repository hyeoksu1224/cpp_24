# Makefile
CC = g++
CCFLAGS = -g

VirtualDestructor: main.o Animal.o Dog.o Cat.o
	$(CC) $(CCFLAGS) -o VirtualDestructor main.o Animal.o Dog.o Cat.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<