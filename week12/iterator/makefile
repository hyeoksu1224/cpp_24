#MakeFile
CC = g++
CCFLAGS = -g

iterator: iterator.o
	$(CC) $(CCFLAGS) -o iterator iterator.o

clean:
	rm -f *.o

%.o: %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<