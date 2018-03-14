#ifndef BOARD_H
#define BOARD_H

typedef struct{
	char x;
	char y;
}piece;

typedef struct{
	piece p;
	int color;
}pawn;

int get_move(piece *, char *, char *);

int get_move_pawn(pawn *, char *, char *);

#endif