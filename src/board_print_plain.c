#include "board_print_plain.h"

void board_init(board *board_e)
{
	for(int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board_e->board[i][j] = '.';	
		}
	}
}

void board_print(board *board_e, pawn *pawns)
{
	printf("\033[2J");
	printf("\033[0;0f");
	board_init(board_e);

	for(int i = 0; i < 16; i++)
		set_pawn(&pawns[i], board_e);

	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if(isupper(board_e->board[i][j]) && (board_e->board[i][j] != '.'))
				printf("\x1b[31;1m");
			else if(islower(board_e->board[i][j]) && (board_e->board[i][j] != '.'))
				printf("\x1b[32;1m");

			printf("%c ", board_e->board[i][j]);

			printf("\x1b[39;1m");
		}
		printf("\n");
	}
}

void point_to_coordinates(char x, char y, coordinate *c)
{
	c->x = x - 'a';

	c->y = y - '1';
}

void set_pawn(pawn *pawns, board *board_e)
{
	coordinate coordinate_pawn;

	point_to_coordinates(pawns->p.x, pawns->p.y, &coordinate_pawn);

	if(pawns->color == 1){
		board_e->board[coordinate_pawn.y][coordinate_pawn.x] = 'P';
	} else {
		board_e->board[coordinate_pawn.y][coordinate_pawn.x] = 'p';
	}
}