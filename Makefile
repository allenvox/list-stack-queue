.PHONY: main
all: main
main: main.c classes.c
	g++ -Wall -Wextra -o $@ $^

clean:
	rm -rf *.o main