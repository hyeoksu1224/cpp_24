# Makefile
CC = g++
CCFLAGS = -g

ClassTemplate: ClassTemplate.o
	$(CC) $(CCFLAGS) -o ClassTemplate ClassTemplate.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<