all: prog clean

prog: main.o board.o board_print_plain.o bin
	gcc -std=c11 bin/main.o bin/board.o bin/board_print_plain.o -o chessviz
main.o: src/chessviz.c bin
	gcc -std=c11 -c src/chessviz.c -o bin/main.o
board.o: src/board.c bin
	gcc -std=c11 -c src/board.c -o bin/board.o
board_print_plain.o: src/board_print_plain.c bin
	gcc -std=c11 -c src/board_print_plain.c -o bin/board_print_plain.o
clean:
	rm -rf *.o bin/*.o
bin:
	mkdir bin