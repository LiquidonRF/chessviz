#ifndef BOARD_PRINT_PLAIN_H
#define BOARD_PRINT_PLAIN_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "board.h"

typedef struct{
	char board[8][8];	
} board;

typedef struct{
	int x;
	int y;
}coordinate;

void board_init(board *board_e);

void board_print(board *board_e, pawn *pawns);

void point_to_coordinates(char x, char y, coordinate *c);

void set_pawn(pawn *pawns, board *board_e);

#endif