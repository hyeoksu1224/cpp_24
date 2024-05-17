# Makefile
CC = g++
CCFLAGS = -g

Circle: main.o Circle.o Point.o
	$(CC) $(CCFLAGS) -o Circle main.o Circle.o Point.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<