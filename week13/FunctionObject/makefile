CC = g++
CCFLAGS = -g

functor: functor.o
	$(CC) $(CCFLAGS) -o functor functor.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<