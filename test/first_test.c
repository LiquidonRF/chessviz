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

	turn[0] = 'e';
	turn[1] = '2';
	turn[2] = 'e';
	turn[3] = '3';

	int check2 = pawn_check(pieces, search_piece(turn[0], turn[1], pieces), turn[2], turn[3]);

	turn[0] = 'e';
	turn[1] = '2';
	turn[2] = 'd';
	turn[3] = '3';

	int check3 = pawn_check(pieces, search_piece(turn[0], turn[1], pieces), turn[2], turn[3]);

	int expected1 = 0;
	int expected2 = 0;
	int expected3 = -1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);

}

CTEST(move_piece, move_rook)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('a', '2', pieces), 'a', '4');

	char turn[5];

	turn[0] = 'a';
	turn[1] = '1';
	turn[2] = 'a';
	turn[3] = '3';

	int check1 = rook_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'a';
	turn[1] = '1';
	turn[2] = 'a';
	turn[3] = '6';

	int check2 = rook_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'a';
	turn[1] = '1';
	turn[2] = 'e';
	turn[3] = '1';

	int check3 = rook_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	int expected1 = 0;
	int expected2 = -1;
	int expected3 = -1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(move_piece, move_horse)
{
	piece *pieces = pieces_init();

	char turn[5];

	turn[0] = 'b';
	turn[1] = '1';
	turn[2] = 'a';
	turn[3] = '3';

	int check1 = horse_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'b';
	turn[1] = '1';
	turn[2] = 'c';
	turn[3] = '3';

	int check2 = horse_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'g';
	turn[1] = '8';
	turn[2] = 'h';
	turn[3] = '6';

	int check3 = horse_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	int expected1 = 0;
	int expected2 = 0;
	int expected3 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(move_piece, move_elephant)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('e', '2', pieces), 'e', '4');


	char turn[5];

	turn[0] = 'f';
	turn[1] = '1';
	turn[2] = 'a';
	turn[3] = '6';

	int check1 = elephant_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'f';
	turn[1] = '1';
	turn[2] = 'e';
	turn[3] = '2';

	int check2 = elephant_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'c';
	turn[1] = '1';
	turn[2] = 'e';
	turn[3] = '3';

	int check3 = elephant_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	int expected1 = 0;
	int expected2 = 0;
	int expected3 = -1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);

}

CTEST(move_piece, move_king)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('e', '2', pieces), 'e', '4');


	char turn[5];

	turn[0] = 'd';
	turn[1] = '1';
	turn[2] = 'e';
	turn[3] = '2';

	int check1 = king_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'd';
	turn[1] = '1';
	turn[2] = 'e';
	turn[3] = '5';

	int check2 = king_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'd';
	turn[1] = '1';
	turn[2] = 'd';
	turn[3] = '3';

	int check3 = king_check(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	int expected1 = 0;
	int expected2 = -1;
	int expected3 = -1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(move_piece, move_queen)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('e', '2', pieces), 'e', '4');


	char turn[5];

	turn[0] = 'e';
	turn[1] = '1';
	turn[2] = 'e';
	turn[3] = '3';

	int check1 = get_move_queen(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'e';
	turn[1] = '3';
	turn[2] = 'a';
	turn[3] = '3';

	int check2 = get_move_queen(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'a';
	turn[1] = '3';
	turn[2] = 'a';
	turn[3] = '5';

	int check3 = get_move_queen(turn[2], turn[3], pieces, search_piece(turn[0], turn[1], pieces));

	int expected1 = 0;
	int expected2 = 0;
	int expected3 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(piece_kill, kill_pawn)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('e', '2', pieces), 'e', '4');
	get_move_pawn(pieces, search_piece('d', '7', pieces), 'd', '5');

	char turn[5];

	turn[0] = 'e';
	turn[1] = '4';
	turn[2] = 'x';
	turn[3] = 'd';
	turn[4] = '5';

	int check1 = pawn_kill(pieces, search_piece(turn[0], turn[1], pieces), turn[3], turn[4]);

	turn[0] = 'd';
	turn[1] = '5';
	turn[2] = 'x';
	turn[3] = 'd';
	turn[4] = '6';

	int check2 = pawn_kill(pieces, search_piece(turn[0], turn[1], pieces), turn[3], turn[4]);

	turn[0] = 'd';
	turn[1] = '5';
	turn[2] = 'x';
	turn[3] = 'd';
	turn[4] = '4';

	int check3 = pawn_kill(pieces, search_piece(turn[0], turn[1], pieces), turn[3], turn[4]);

	int expected1 = 0;
	int expected2 = -1;
	int expected3 = -1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(piece_kill, kill_rook)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('a', '2', pieces), 'a', '4');
	get_move_rook('a', '3', pieces, search_piece('a', '1', pieces));
	get_move_rook('b', '3', pieces, search_piece('a', '3', pieces));

	char turn[5];

	turn[0] = 'b';
	turn[1] = '3';
	turn[2] = 'x';
	turn[3] = 'a';
	turn[4] = '3';

	int check1 = rook_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'b';
	turn[1] = '3';
	turn[2] = 'x';
	turn[3] = 'b';
	turn[4] = '7';

	int check2 = rook_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));
	
	turn[0] = 'b';
	turn[1] = '7';
	turn[2] = 'x';
	turn[3] = 'b';
	turn[4] = '2';

	int check3 = rook_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));
	
	int expected1 = -1;
	int expected2 = 0;
	int expected3 = -1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(piece_kill, kill_horse)
{
	piece *pieces = pieces_init();

	get_move_horse('a', '3', pieces, search_piece('b', '1', pieces));
	get_move_horse('b', '5', pieces, search_piece('a', '3', pieces));

	char turn[5];

	turn[0] = 'b';
	turn[1] = '5';
	turn[2] = 'x';
	turn[3] = 'a';
	turn[4] = '7';

	int check1 = horse_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'a';
	turn[1] = '7';
	turn[2] = 'x';
	turn[3] = 'a';
	turn[4] = '7';

	int check2 = horse_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));
	
	turn[0] = 'a';
	turn[1] = '7';
	turn[2] = 'x';
	turn[3] = 'c';
	turn[4] = '8';

	int check3 = horse_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));
	
	int expected1 = 0;
	int expected2 = -1;
	int expected3 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(piece_kill, kill_elephant)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('e', '2', pieces), 'e', '4');
	get_move_pawn(pieces, search_piece('a', '7', pieces), 'a', '6');

	char turn[5];

	turn[0] = 'f';
	turn[1] = '1';
	turn[2] = 'x';
	turn[3] = 'a';
	turn[4] = '6';

	int check1 = elephant_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'a';
	turn[1] = '6';
	turn[2] = 'x';
	turn[3] = 'a';
	turn[4] = '6';

	int check2 = elephant_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'a';
	turn[1] = '6';
	turn[2] = 'x';
	turn[3] = 'b';
	turn[4] = '7';

	int check3 = elephant_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	int expected1 = 0;
	int expected2 = -1;
	int expected3 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(piece_kill, kill_king)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('e', '2', pieces), 'e', '4');
	get_move_king('e', '2', pieces, search_piece('d', '1', pieces));
	get_move_king('d', '3', pieces, search_piece('e', '2', pieces));
	get_move_pawn(pieces, search_piece('d', '7', pieces), 'd', '5');
	get_move_pawn(pieces, search_piece('d', '5', pieces), 'd', '4');

	char turn[5];

	turn[0] = 'd';
	turn[1] = '3';
	turn[2] = 'x';
	turn[3] = 'd';
	turn[4] = '4';

	int check1 = king_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'd';
	turn[1] = '4';
	turn[2] = 'x';
	turn[3] = 'd';
	turn[4] = '4';

	int check2 = king_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'd';
	turn[1] = '4';
	turn[2] = 'x';
	turn[3] = 'd';
	turn[4] = '5';

	int check3 = king_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	int expected1 = 0;
	int expected2 = -1;
	int expected3 = -1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}

CTEST(piece_kill, kill_queen)
{
	piece *pieces = pieces_init();

	get_move_pawn(pieces, search_piece('d', '2', pieces), 'd', '4');
	get_move_pawn(pieces, search_piece('a', '7', pieces), 'a', '5');

	char turn[5];

	turn[0] = 'e';
	turn[1] = '1';
	turn[2] = 'x';
	turn[3] = 'a';
	turn[4] = '5';

	int check1 = queen_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'a';
	turn[1] = '5';
	turn[2] = 'x';
	turn[3] = 'a';
	turn[4] = '5';

	int check2 = queen_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	turn[0] = 'a';
	turn[1] = '5';
	turn[2] = 'x';
	turn[3] = 'c';
	turn[4] = '7';

	int check3 = queen_kill(turn[3], turn[4], pieces, search_piece(turn[0], turn[1], pieces));

	int expected1 = 0;
	int expected2 = -1;
	int expected3 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
}