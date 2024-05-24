CC = g++
CCFLAGS = -g

templateVector: templateVector.o
	$(CC) $(CCFLAGS) -o templateVector templateVector.o

vector: vector.o
	$(CC) $(CCFLAGS) -o vector vector.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<