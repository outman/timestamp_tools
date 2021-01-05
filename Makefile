build:
	mkdir build && cc src/main.c -o build/td.o
install:
	cp build/td.o /usr/local/bin/td
clean:
	rm -f build
