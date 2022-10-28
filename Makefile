.PHONY: main
all: main
main: main.cpp classes.cpp
	g++ -Wall -Wextra -o $@ $^

clean:
	rm -rf *.o main