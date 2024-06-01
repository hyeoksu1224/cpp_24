CC = g++
CCFLAGS = -g

PriQue: PQueue.o
	$(CC) $(CCFLAGS) -o PriQue PQueue.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<