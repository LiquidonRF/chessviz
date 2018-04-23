#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
	char x;
	char y;
	char type;
	int dead;
}piece;

piece *pieces_init();

void get_move(piece *, char, char);

int get_move_pawn(piece *, piece *, char, char);

piece *search_piece(char, char, piece *);

int get_move_rook(char, char, piece *, piece *);

//nt is_piece_in_coord(char x, char y, pawn *pawns);

#endif