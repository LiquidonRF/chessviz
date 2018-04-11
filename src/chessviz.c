#include <stdio.h>
#include <ctype.h>
#include "board.h"
#include "board_print_plain.h"

int main()
{
	board board_e; 
	pawn *pawns = pawn_init();

	char turn[4];
	int end = 0;
	
	board_print(&board_e, pawns);

	while(end != 1){
		printf("Enter move: ");
		scanf("%s", turn);

		int flag = get_move_pawn(search_pawn(turn[0], turn[1], pawns), turn[2], turn[3]);
		printf("%d\n", flag);

		board_print(&board_e, pawns);
	}
	return 0;
}