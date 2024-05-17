# Makefile
CC = g++
CCFLAGS = -g

AbstractClass: main.o Refrigerator.o Television.o
	$(CC) $(CCFLAGS) -o AbstractClass main.o Refrigerator.o Television.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<