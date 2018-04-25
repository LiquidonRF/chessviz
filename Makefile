compile_flags = -Wall -Werror -std=c99 -lm

all: ./bin/chessviz ./bin/test

bin/chessviz: build/main.o build/board.o build/board_print_plain.o
	gcc $(compile_flags) -o bin/chessviz build/main.o build/board.o build/board_print_plain.o

build/main.o: src/chessviz.c src/board.h
	gcc $(compile_flags) -o build/main.o -c src/chessviz.c

build/board.o: src/board.c
	gcc $(compile_flags) -o build/board.o -c src/board.c

build/board_print_plain.o: src/board_print_plain.c
	gcc $(compile_flags) -o build/board_print_plain.o -c src/board_print_plain.c

bin/test: build/test.o build/first_test.o build/board.o build/board_print_plain.o
	gcc $(compile_flags) -o bin/test build/test.o build/first_test.o build/board.o build/board_print_plain.o

build/test.o: test/test.c
	gcc $(compile_flags) -o build/test.o -c test/test.c -Ithirdparty -Isrc

build/first_test.o: test/first_test.c
	gcc $(compile_flags) -o build/first_test.o -c test/first_test.c -Ithirdparty -Isrc

.PHONY: clean adddir open gdb
adddir:
	mkdir build bin
clean:
	rm -rf build/ bin/
open:
	./bin/chessviz
gdb:
	gdb ./bin/chessviz