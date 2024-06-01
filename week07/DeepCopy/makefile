# Makefile
CC = g++
CCFLAGS = -g

Student: main.o Student.o
	$(CC) $(CCFLAGS) -o Student main.o Student.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<