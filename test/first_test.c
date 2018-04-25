#include <stdio.h>
#include <ctest.h>
#include "board.h"
#include "board_print_plain.h"

CTEST(move_piece, move_pawn)
{
	piece *pieces = pieces_init();

	char turn[5];

	turn[0] = 'e';
	turn[1] = '2';
	turn[2] = 'e';
	turn[3] = '4';

	int check1 = pawn_check(pieces, search_piece(turn[0], turn[1], pieces), turn[2], turn[3]);

	int expected1 = 0;

	ASSERT_EQUAL(expected1, check1);

}