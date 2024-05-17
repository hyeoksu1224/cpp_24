# Makefile
CC = g++
CCFLAGS = -g

MyString: main.o MyString.o
	$(CC) $(CCFLAGS) -o MyString main.o MyString.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<