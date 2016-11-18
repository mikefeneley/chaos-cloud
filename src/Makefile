CC=g++
CFLAGS= -c
LDFLAGS=
I = -I /usr/local/boost_1_60_0 

SOURCES = main.cpp daemon_manager.cpp chaos_daemon.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = run 

all:$(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(I) $(CFLAGS) $< -o $@

clean:
	-rm *.txt
	-rm *.o
	-rm chaos_monitor
	-rm a.out
