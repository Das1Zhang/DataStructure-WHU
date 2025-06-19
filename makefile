.PHONY: clean all

all: main
	echo "all done"

clean:
	rm -f hello world *.o

main: %.o
	g++ $@ -o main

%.o: %.cpp
	g++ -c $^ -o $@