.PHONY: clean all

all: hello world
	echo "all done"

hello: main.o message.o
	g++ main.o message.o -o hello

world: main.o message.o
	g++ main.o message.o -o world
main.o: main.cpp
	g++ -c main.cpp
message.o: message.cpp
	g++ -c message.cpp

clean:
	rm -f hello world *.o