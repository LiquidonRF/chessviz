#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char x;
	char y;
}piece;

typedef struct{
	piece p;
	int color;
}pawn;

pawn *pawn_init();

int get_move(piece *, char, char);

int get_move_pawn(pawn *, char, char);

pawn *search_pawn(char, char, pawn *);

#endif