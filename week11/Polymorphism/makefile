# Makefile
CC = g++
CCFLAGS = -g

Polymorphism: main.o Shape.o Rectangle.o Circle.o
	$(CC) $(CCFLAGS) -o Polymorphism main.o Shape.o Rectangle.o Circle.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<