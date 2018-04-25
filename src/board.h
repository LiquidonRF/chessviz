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

int get_move_queen(char x, char y, piece *pieces, piece *queen);

int pawn_check(piece *pieces, piece *pawn, char x, char y);

int rook_check(char x, char y, piece *pieces, piece *rook);

int horse_check(char x, char y, piece *pieces, piece *horse);

int elephant_check(char x, char y, piece *pieces, piece *elephant);

int king_check(char x, char y, piece *pieces, piece *king);

int pawn_kill(piece *pieces, piece *pawn, char x, char y);

int rook_kill(char x, char y, piece *pieces, piece *rook);

int horse_kill(char x, char y, piece *pieces, piece *horse);

int elephant_kill(char x, char y, piece *pieces, piece *elephant);

int king_kill(char x, char y, piece *pieces, piece *king);

int queen_kill(char x, char y, piece *pieces, piece *queen);

int check_end(piece *pieces);

#endif