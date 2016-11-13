CC=g++
I = -I /usr/local/boost_1_60_0

all: chaos_monitor

chaos_monitor: main.o
	$(CC) main.o

main.o: main.cpp
	$(CC) $(I) -c main.cpp
clean:
	-rm *.txt
	-rm *.o
	-rm chaos_monitor
	-rm a.out
