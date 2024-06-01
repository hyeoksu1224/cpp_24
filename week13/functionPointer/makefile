CC = g++
CCFLAGS = -g

FuncPtr: fptr.o
	$(CC) $(CCFLAGS) -o FuncPtr fptr.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<