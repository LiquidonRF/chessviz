#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

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

int get_turn(piece *pieces, int turn);

int get_move_horse(char x, char y, piece *pieces, piece *horse);

int get_move_elephant(char x, char y, piece *pieces, piece *elephant);

int get_move_king(char x, char y, piece *pieces, piece *king);

//nt is_piece_in_coord(char x, char y, pawn *pawns);

#endif