#include <stdio.h>
#include <ctype.h>
#include "board.h"
#include "board_print_plain.h"

int main()
{
	int turn = 0;
	board board_e; 
	piece *pieces = pieces_init();

	int end = 0;
	
	board_print(&board_e, pieces);

	while(end != -1){
		int flag = get_turn(pieces, turn);

		printf("%d\n", flag);

		board_print(&board_e, pieces);

		if (flag == 0)
			turn++;

	end = check_end(pieces);
	}
	return 0;
}