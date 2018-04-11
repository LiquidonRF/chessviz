compile_flags = -Wall -Werror -std=c99

./bin/chessviz: ./build/main.o ./build/board.o ./build/board_print_plain.o
	gcc $(compile_flags) -o ./bin/chessviz ./build/main.o ./build/board.o ./build/board_print_plain.o

./build/main.o: ./src/chessviz.c ./src/board.h ./src/board_print_plain.h
	gcc $(compile_flags) -o build/main.o -c src/chessviz.c

./build/board.o: ./src/board.c ./src/board.h
	gcc $(compile_flags) -o ./build/board.o -c ./src/board.c

./build/board_print_plain.o: ./src/board_print_plain.c ./src/board_print_plain.h
	gcc $(compile_flags) -o ./build/board_print_plain.o -c ./src/board_print_plain.c

.PHONY: clean adddir open gdb
adddir:
	mkdir build bin
clean:
	rm -rf ./build/ ./bin/
open:
	./bin/chessviz
gdb:
	gdb ./bin/chessviz