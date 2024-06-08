# Makefile
CC = g++
CCFLAGS = -g

unmodifying1 : unmodifying1.o
	$(CC) $(CCFLAGS) -o unmodifying1 unmodifying1.o

unmodifying2 : unmodifying2.o
	$(CC) $(CCFLAGS) -o unmodifying2 unmodifying2.o

unmodifying3 : unmodifying3.o
	$(CC) $(CCFLAGS) -o unmodifying3 unmodifying3.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<