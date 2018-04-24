#include "board.h"

piece *pieces_init()
{
	piece *pieces = (piece *)malloc(sizeof(pieces) * 32);

	char key = 'a';

	for (int i = 0; i < 16; i += 2) {
		pieces[i].dead = 0;
		pieces[i + 1].dead = 0;
		pieces[i].type = 'p';
		pieces[i + 1].type = 'P';
		pieces[i].y = '7';
		pieces[i + 1].y = '2';
		pieces[i].x = key;
		pieces[i + 1].x = key;
		key++;
	}

	pieces[16].type = 'r';
    pieces[16].dead = 0;
    pieces[16].x = 'a';
    pieces[16].y = '8';

    pieces[17].type = 'R';
    pieces[17].dead = 0;
    pieces[17].x = 'h';
    pieces[17].y = '1';

    pieces[18].type = 'r';
    pieces[18].dead = 0;
    pieces[18].x = 'h';
    pieces[18].y = '8';

    pieces[19].type = 'R';
    pieces[19].dead = 0;
    pieces[19].x = 'a';
    pieces[19].y = '1';

    pieces[20].type = 'h';
    pieces[20].dead = 0;
    pieces[20].x = 'b';
    pieces[20].y = '8';

    pieces[21].type = 'H';
    pieces[21].dead = 0;
    pieces[21].x = 'g';
    pieces[21].y = '1';

    pieces[22].type = 'h';
    pieces[22].dead = 0;
    pieces[22].x = 'g';
    pieces[22].y = '8';

    pieces[23].type = 'H';
    pieces[23].dead = 0;
    pieces[23].x = 'b';
    pieces[23].y = '1';

    pieces[24].type = 'e';
    pieces[24].dead = 0;
    pieces[24].x = 'c';
    pieces[24].y = '8';

    pieces[25].type = 'E';
    pieces[25].dead = 0;
    pieces[25].x = 'f';
    pieces[25].y = '1';

    pieces[26].type = 'e';
    pieces[26].dead = 0;
    pieces[26].x = 'f';
    pieces[26].y = '8';

    pieces[27].type = 'E';
    pieces[27].dead = 0;
    pieces[27].x = 'c';
    pieces[27].y = '1';

    pieces[28].type = 'K';
    pieces[28].dead = 0;
    pieces[28].x = 'd';
    pieces[28].y = '1';

    pieces[29].type = 'k';
    pieces[29].dead = 0;
    pieces[29].x = 'd';
    pieces[29].y = '8';

    pieces[30].type = 'Q';
    pieces[30].dead = 0;
    pieces[30].x = 'e';
    pieces[30].y = '1';

    pieces[31].type = 'q';
    pieces[31].dead = 0;
    pieces[31].x = 'e';
    pieces[31].y = '8';

	return pieces;
}

void get_move(piece *p, char x, char y)
{
		p->x = x;
		p->y = y;
}

int get_move_pawn(piece *pieces, piece *pawn, char x, char y)
{
    if (search_piece(x, y, pieces) == NULL) {

    int flag = pawn_check(pieces, pawn, x, y);
    if (flag == -1)
    	return -1;

    get_move(pawn, x, y);
    return 0;
	}
    return -1;
}

piece *search_piece(char x, char y, piece *pieces)
{
    for (int i = 0; i < 32; i++) {
        if (pieces[i].x == x && pieces[i].y == y && pieces[i].dead == 0){
            return &pieces[i];
        }
    }
    return NULL;
}

int get_move_rook(char x, char y, piece *pieces, piece *rook)
{
	if (search_piece(x, y, pieces) == NULL) {
		int flag = rook_check(x, y, pieces, rook);

		if (flag == -1)
			return -1;

		get_move(rook, x, y);
		return 0;
	}
	return -1;
}

int get_turn(piece *pieces, int turn)
{
	char command[10];
	printf("Enter turn: ");
	scanf("%s", command);

	if (command[2] != 'x') {
		char x = command[0];
		char y = command[1];
		char x1 = command[2];
		char y1 = command[3];
		piece *kek;
		int flag = 0;

		if (x <= 'h' && x >= 'a' && y <= '8' && y >= '1'){
			if (x1 <= 'h' && x1 >= 'a' && y1 <= '8' && y1 >= '1'){
				kek = search_piece(x, y, pieces);
				if (kek != NULL) {
					printf("check\n");
					if (kek->type == 'P' && turn % 2 == 0) {
						flag = get_move_pawn(pieces, kek, x1, y1);
						if (flag == -1)
							return -1;
						return 0;
					} else if (kek->type == 'p' && turn % 2 == 1) {
						flag = get_move_pawn(pieces, kek, x1, y1);
						if (flag == -1)
							return -1;
						return 0;
					}
					if (kek->type == 'R' && turn % 2 == 0) {
						flag = get_move_rook(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					} else if (kek->type == 'r' && turn % 2 == 1) {
						flag = get_move_rook(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					}
					if (kek->type == 'H' && turn % 2 == 0) {
						flag = get_move_horse(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					} else if (kek->type == 'h' && turn % 2 == 1) {
						flag = get_move_horse(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					}
					if (kek->type == 'E' && turn % 2 == 0) {
						flag = get_move_elephant(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					} else if (kek->type == 'e' && turn % 2 == 1) {
						flag = get_move_elephant(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					}
					if (kek->type == 'K' && turn % 2 == 0) {
						flag = get_move_king(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					} else if (kek->type == 'k' && turn % 2 == 1) {
						flag = get_move_king(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					}
					if (kek->type == 'Q' && turn % 2 == 0) {
						flag = get_move_queen(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					} else if (kek->type == 'q' && turn % 2 == 1) {
						flag = get_move_queen(x1, y1, pieces, kek);
						if (flag == -1)
							return -1;
						return 0;
					}
				}
			}
		}
	} else if (command[2] == 'x') {
		char x = command[0];
		char y = command[1];
		char x1 = command[3];
		char y1 = command[4];

		if (x <= 'h' && x >= 'a' && y <= '8' && y >= '1'){
			if (x1 <= 'h' && x1 >= 'a' && y1 <= '8' && y1 >= '1'){
				piece *kek = search_piece(x, y, pieces);
				if (kek->type == 'P' || kek->type == 'p') {
					int flag = pawn_kill(pieces, kek, x1, y1);
					if (flag == -1)
						return -1;
					return 0;
				}
			}
		}
	}
	return -1;
}

int get_move_horse(char x, char y, piece *pieces, piece *horse)
{
	if (search_piece(x, y, pieces) == NULL) {
		if (horse->y + 2 == y && (horse->x + 1 == x || horse->x - 1 == x)) {
			get_move(horse, x, y);
			return 0;
		}
		if (horse->y - 2 == y && (horse->x + 1 == x || horse->x - 1 == x)) {
			get_move(horse, x, y);
			return 0;
		}
		if (horse->y + 1 == y && (horse->x + 2 == x || horse->x - 2 == x)) {
			get_move(horse, x, y);
			return 0;
		}
		if (horse->y - 1 == y && (horse->x + 2 == x || horse->x - 2 == x)) {
			get_move(horse, x, y);
			return 0;
		}
	}
	return -1;
}


int get_move_elephant(char x, char y, piece *pieces, piece *elephant)
{
	if (search_piece(x, y, pieces) == NULL) {
        if (abs(elephant->x - x) == abs(elephant->y - y)) {
        	if (x > elephant->x && y > elephant->y) {
        		for (int i = elephant->y + 1, j = elephant->x + 1; i <= y; i++, j++) {
        			if (search_piece(j, i, pieces) != NULL)
        				return -1;
        		}
        	}
        	if (x < elephant->x && y > elephant->y) {
        		for (int i = elephant->y + 1, j = elephant->x - 1; i <= y; i++, j--) {
        			if (search_piece(j, i, pieces) != NULL)
        				return -1;
        		}
        	}
        	if (x < elephant->x && y < elephant->y) {
        		for (int i = elephant->y - 1, j = elephant->x - 1; i >= y; i--, j--) {
        			if (search_piece(j, i, pieces) != NULL)
        				return -1;
        		}
        	}
        	if (x > elephant->x && y < elephant->y) {
        		for (int i = elephant->y - 1, j = elephant->x + 1; i >= y; i--, j++) {
        			if (search_piece(j, i, pieces) != NULL)
        				return -1;
        		}
        	}
            get_move(elephant, x, y);
            return 0;
        }
    }
    return -1;
}

int get_move_king(char x, char y, piece *pieces, piece *king)
{
	if (search_piece(x, y, pieces) == NULL) {
		if (abs(x - king->x) <= 1 && abs(y - king->y) <= 1) {
			get_move(king, x, y);
			return 0;
		}
	}
	return -1;
}

int get_move_queen(char x, char y, piece *pieces, piece *queen)
{
	int flag1 = get_move_rook(x, y, pieces, queen);
	int flag2 = get_move_elephant(x, y, pieces, queen);

	if (flag1 == 0 || flag2 == 0) {
		return 0;
	}
	return -1;
}

int pawn_check(piece *pieces, piece *pawn, char x, char y)
{
	if (pawn->x != x)
            return -1;

	if (isupper(pawn->type)) {                                            //Для белых
        if (pawn->y == '2'){                                    //С начальной позиции
            if ((y - pawn->y) == 2 || (y - pawn->y) == 1){            //Движение на 2 клетки
                return 0;
            }
        } else {
            if ((y - pawn->y) == 1){                            //Движение на одну клетку
                return 0;
            }
        }
    } else {                                                    //Для черных
        if (pawn->y == '7'){                                    //С начальной позиции
            if ((pawn->y - y) == 2 || (pawn->y - y) == 1){      //Движение на две клетки
                return 0;
            }
        } else {
            if ((pawn->y - y) == 1){                            //Движение на одну клетку
                return 0;
            }
        }
    }
    return -1;
}

int rook_check(char x, char y, piece *pieces, piece *rook)
{
	if (rook->x == x) {
		if (y < rook->y) {
			for (int i = y + 1; i < rook->y; i++) {
				if (search_piece(x, i, pieces) != NULL) {
					return -1;
				}
			}
			return 0;
		} else if (y > rook->y) {
			for (int i = rook->y + 1; i < y; i++) {
				if (search_piece(x, i, pieces) != NULL) {
					return -1;
				}
			}
			return 0;
		}
	} else if (rook->y == y) {
		if (x < rook->x) {
			for (int i = x + 1; i < rook->x; i++) {
				if (search_piece(i, y, pieces) != NULL) {
					return -1;
				}
			}
			return 0;
		} else if (x > rook->x) {
			for (int i = rook->x + 1; i < x; i++) {
				if (search_piece(i, y, pieces) != NULL) {
					return -1;
				}
			}
			return 0;
		}
	}
	return -1;
}

int pawn_kill(piece *pieces, piece *pawn, char x, char y)
{
	piece *kill;
	if ((kill = search_piece(x, y, pieces)) != NULL) {
		if (abs(x - pawn->x) == 1) {
			if (isupper(pawn->type) && y - pawn->y == 1) {
				pawn->x = x;
				pawn->y = y;
				kill->dead = 1;
				return 0;
			}
			if (islower(pawn->type) && pawn->y -y == 1) {
				pawn->x = x;
				pawn->y = y;
				kill->dead = 1;
				return 0;
			}
		}
	}
	return -1;
}

int rook_kill(char x, char y, piece *pieces, piece *rook)
{
	return -1;
}