CC = g++
CCFLAGS = -g

Deque: deque.o
	$(CC) $(CCFLAGS) -o Deque deque.o

List: list.o
	$(CC) $(CCFLAGS) -o List list.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<