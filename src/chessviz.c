#include <stdio.h>
#include <ctype.h>
#include "board.h"
#include "board_print_plain.h"

int main()
{
	board board_e; 
	board_init(&board_e);
	pawn *pawns = pawn_init();

	char turn[4];
	for(int i = 0; i < 16; i++)
		set_pawn(&pawns[i], &board_e);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%c ", board_e.board[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i < 4; i++)
	{
		turn[i] = tolower(getchar());
	}

	int flag = get_move_pawn(search_pawn(turn[0], turn[1], pawns), turn[2], turn[3]);
	printf("%d\n", flag);

	board_init(&board_e);

	for(int i = 0; i < 16; i++)
		set_pawn(&pawns[i], &board_e);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%c ", board_e.board[i][j]);
		}
		printf("\n");
	}
}