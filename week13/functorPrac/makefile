CC = g++
CCFLAGS = -g

RectangleCmp: RectangleCmp.o
	$(CC) $(CCFLAGS) -o RectangleCmp RectangleCmp.o

myGreater: myGreater.o
	$(CC) $(CCFLAGS) -o myGreater myGreater.o

sortorderchan: sortorderchan.o
	$(CC) $(CCFLAGS) -o sortorderchan sortorderchan.o

TemplateSwap: TemplateSwap.o
	$(CC) $(CCFLAGS) -o TemplateSwap TemplateSwap.o

summary: summary.o
	$(CC) $(CCFLAGS) -o summary summary.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<