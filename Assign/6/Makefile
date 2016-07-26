EXE = hw6

all: $(EXE)

OBJS = HashTable.o Assignment6.o
CFLAGS = -Wall -std=c++11

HashTable.o: HashTable.cpp HashTable.h
	g++ $(CFLAGS) -c -o HashTable.o HashTable.cpp

Assignment6.o: Assignment6.cpp
	g++ $(CFLAGS) -c -o Assignment6.o Assignment6.cpp

hw6: $(OBJS)
	g++ -Wall -o hw6 $(OBJS)

clean:
	$(RM) *.o
