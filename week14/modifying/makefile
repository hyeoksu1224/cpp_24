# Makefile
CC = g++
CCFLAGS = -g

modifying1 : modifying1.o
	$(CC) $(CCFLAGS) -o modifying1 modifying1.o

modifying2 : modifying2.o
	$(CC) $(CCFLAGS) -o modifying2 modifying2.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<