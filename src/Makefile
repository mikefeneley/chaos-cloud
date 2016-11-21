CC=g++
CFLAGS= -c -std=c++11
LDFLAGS= -I /usr/local/boost_1_60_0/stage/lib -lsqlite3 
I = -I /usr/local/boost_1_60_0 -I /usr/lib/sqlite-autoconf-3150100
SOURCES = main.cpp daemon_manager.cpp chaos_daemon.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = run 

all:$(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(I) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(I) $(CFLAGS) $< -o $@

clean:
	-rm *.txt
	-rm *.o
	-rm chaos_monitor
	-rm a.out
