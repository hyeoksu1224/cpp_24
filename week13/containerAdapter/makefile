CC = g++
CCFLAGS = -g

StackQueue: StackQueue.o
	$(CC) $(CCFLAGS) -o StackQueue StackQueue.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<