CC = g++
CCFLAGS = -g

lambda: lambda.o
	$(CC) $(CCFLAGS) -o lambda lambda.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<