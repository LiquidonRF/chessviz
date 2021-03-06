#include "board.h"

piece *pieces_init()
{
    piece *pieces = (piece *)malloc(sizeof(pieces) * 32);
    for (int i = 0; i < 32; i++) {
        pieces[i].dead = 0;
    }

    char key = 'a';

    for (int i = 0; i < 16; i++) {
        pieces[i].type = (i < 8) ? 'P' : 'p';
        pieces[i].y = (i < 8) ? '2' : '7';
        pieces[i].x = key;
        key = (key < 'a' + 7) ? key + 1 : 'a';
    }

    pieces[16].type = 'r';
    pieces[16].x = 'a';
    pieces[16].y = '8';

    pieces[17].type = 'R';
    pieces[17].x = 'h';
    pieces[17].y = '1';

    pieces[18].type = 'r';
    pieces[18].x = 'h';
    pieces[18].y = '8';

    pieces[19].type = 'R';
    pieces[19].x = 'a';
    pieces[19].y = '1';

    pieces[20].type = 'h';
    pieces[20].x = 'b';
    pieces[20].y = '8';

    pieces[21].type = 'H';
    pieces[21].x = 'g';
    pieces[21].y = '1';

    pieces[22].type = 'h';
    pieces[22].x = 'g';
    pieces[22].y = '8';

    pieces[23].type = 'H';
    pieces[23].x = 'b';
    pieces[23].y = '1';

    pieces[24].type = 'e';
    pieces[24].x = 'c';
    pieces[24].y = '8';

    pieces[25].type = 'E';
    pieces[25].x = 'f';
    pieces[25].y = '1';

    pieces[26].type = 'e';
    pieces[26].x = 'f';
    pieces[26].y = '8';

    pieces[27].type = 'E';
    pieces[27].x = 'c';
    pieces[27].y = '1';

    pieces[28].type = 'K';
    pieces[28].x = 'd';
    pieces[28].y = '1';

    pieces[29].type = 'k';
    pieces[29].x = 'd';
    pieces[29].y = '8';

    pieces[30].type = 'Q';
    pieces[30].x = 'e';
    pieces[30].y = '1';

    pieces[31].type = 'q';
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

        if (pawn_check(pieces, pawn, x, y) == -1)
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
        if (rook_check(x, y, pieces, rook) == -1)
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

    char x, y, x1, y1;
    x = command[0];
    y = command[1];

    if (command[2] != 'x') {
        x1 = command[2];
        y1 = command[3];
    } else if(command[2] == 'x'){
        x1 = command[3];
        y1 = command[4];
    }

    if ((x > 'h' || x < 'a' || y > '8' || y < '1')
        || (x1 > 'h' || x1 < 'a' || y1 > '8' || y1 < '1')) {
        return -1;
    }

    piece *kek = search_piece(x, y, pieces);

    if (isupper(kek->type) == turn % 2)
        return -1;

    if (command[2] != 'x') {
        if (kek != NULL) {
            printf("check\n");

            char symbol = tolower(kek->type);

            switch (symbol) {
            case 'p':
                if (get_move_pawn(pieces, kek, x1, y1) == -1)
                    return -1;
                return 0;
                break;
            case 'r':
                if (get_move_rook(x1, y1, pieces, kek) == -1)
                    return -1;
                return 0;
                break;
            case 'h':
                if (get_move_horse(x1, y1, pieces, kek) == -1)
                    return -1;
                return 0;
                break;
            case 'e':
                if (get_move_elephant(x1, y1, pieces, kek) == -1)
                    return -1;
                return 0;
                break;
            case 'k':
                if (get_move_king(x1, y1, pieces, kek) == -1)
                    return -1;
                return 0;
                break;
            case 'q':
                if (get_move_queen(x1, y1, pieces, kek) == -1)
                    return -1;
                return 0;
                break;
            }
        }
    } else if (command[2] == 'x') {
        char symbol = tolower(kek->type);

        switch (symbol) {
        case 'p':
            if (pawn_kill(pieces, kek, x1, y1) == -1)
                return -1;
            return 0;
            break;
        case 'r':
            if (rook_kill(x1, y1, pieces, kek) == -1)
                return -1;
            return 0;
            break;
        case 'h':
            if (horse_kill(x1, y1, pieces, kek) == -1)
                return -1;
            return 0;
            break;
        case 'e':
            if (elephant_kill(x1, y1, pieces, kek) == -1)
                return -1;
            return 0;
            break;
        case 'k':
            if (king_kill(x1, y1, pieces, kek) == -1)
                return -1;
            return 0;
            break;
        case 'q':
            if (queen_kill(x1, y1, pieces, kek) == -1)
                return -1;
            return 0;
            break;
        }
    }
    return -1;
}

int get_move_horse(char x, char y, piece *pieces, piece *horse)
{
	if (search_piece(x, y, pieces) == NULL) {

		if (horse_check(x, y, pieces, horse) == 0) {
			get_move(horse, x, y);
			return 0;
		}
	}
	return -1;
}


int get_move_elephant(char x, char y, piece *pieces, piece *elephant)
{
	if (search_piece(x, y, pieces) == NULL) {

		if (elephant_check(x, y, pieces, elephant) == 0) {
			get_move(elephant, x, y);
        	return 0;
		}
    }
    return -1;
}

int get_move_king(char x, char y, piece *pieces, piece *king)
{
	if (search_piece(x, y, pieces) == NULL) {

		if (king_check(x, y, pieces, king) == 0) {
			get_move(king, x, y);
			return 0;
		}
	}
	return -1;
}

int get_move_queen(char x, char y, piece *pieces, piece *queen)
{
    if (get_move_rook(x, y, pieces, queen) == 0 
    || get_move_elephant(x, y, pieces, queen) == 0) {
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

int horse_check(char x, char y, piece *pieces, piece *horse)
{
	if (horse->y + 2 == y && (horse->x + 1 == x || horse->x - 1 == x)) {
		return 0;
	}
	if (horse->y - 2 == y && (horse->x + 1 == x || horse->x - 1 == x)) {
		return 0;
	}
	if (horse->y + 1 == y && (horse->x + 2 == x || horse->x - 2 == x)) {
		return 0;
	}
	if (horse->y - 1 == y && (horse->x + 2 == x || horse->x - 2 == x)) {
		return 0;
	}
	return -1;
}

int elephant_check(char x, char y, piece *pieces, piece *elephant)
{
	if (abs(elephant->x - x) == abs(elephant->y - y)) {
       	if (x > elephant->x && y > elephant->y) {
       		for (int i = elephant->y + 1, j = elephant->x + 1; i < y; i++, j++) {
       			if (search_piece(j, i, pieces) != NULL)
       				return -1;
       		}
       	}
       	if (x < elephant->x && y > elephant->y) {
       		for (int i = elephant->y + 1, j = elephant->x - 1; i < y; i++, j--) {
       			if (search_piece(j, i, pieces) != NULL)
       				return -1;
       		}
       	}
       	if (x < elephant->x && y < elephant->y) {
       		for (int i = elephant->y - 1, j = elephant->x - 1; i > y; i--, j--) {
       			if (search_piece(j, i, pieces) != NULL)
       				return -1;
       		}
       	}
       	if (x > elephant->x && y < elephant->y) {
       		for (int i = elephant->y - 1, j = elephant->x + 1; i > y; i--, j++) {
       			if (search_piece(j, i, pieces) != NULL)
       				return -1;
      		}
    	}
        return 0;
    }
    return -1;
}

int king_check(char x, char y, piece *pieces, piece *king)
{
	if (abs(x - king->x) <= 1 && abs(y - king->y) <= 1) {
		return 0;
	}
	return -1;
}

int pawn_kill(piece *pieces, piece *pawn, char x, char y)
{
	piece *kill;
	if ((kill = search_piece(x, y, pieces)) != NULL
	&& isupper(pawn->type) != isupper(kill->type)) {
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
	piece *kill;
	if ((kill = search_piece(x, y, pieces)) != NULL
	&& isupper(rook->type) != isupper(kill->type)) {
		if (rook_check(x, y, pieces, rook) == 0) {
			rook->x = x;
			rook->y = y;
			kill->dead = 1;
			return 0;
		}
	}
	return -1;
}

int horse_kill(char x, char y, piece *pieces, piece *horse)
{
	piece *kill;
	if ((kill = search_piece(x, y, pieces)) != NULL
	&& isupper(horse->type) != isupper(kill->type)) {
		if (horse_check(x, y, pieces, horse) == 0) {
			horse->x = x;
			horse->y = y;
			kill->dead = 1;
			return 0;
		}
	}
	return -1;
}

int elephant_kill(char x, char y, piece *pieces, piece *elephant)
{
	piece *kill;
	if ((kill = search_piece(x, y, pieces)) != NULL
	&& isupper(elephant->type) != isupper(kill->type)) {
		if (elephant_check(x, y, pieces, elephant) == 0) {
			elephant->x = x;
			elephant->y = y;
			kill->dead = 1;
			return 0;
		}
	}
	return -1;
}

int king_kill(char x, char y, piece *pieces, piece *king)
{
	piece *kill;
	if ((kill = search_piece(x, y, pieces)) != NULL
	&& isupper(king->type) != isupper(kill->type)) {
		if (king_check(x, y, pieces, king) == 0) {
			king->x = x;
			king->y = y;
			kill->dead = 1;
			return 0;
		}
	}
	return -1;
}

int queen_kill(char x, char y, piece *pieces, piece *queen)
{
	piece *kill;
	if ((kill = search_piece(x, y, pieces)) != NULL
	&& isupper(queen->type) != isupper(kill->type)) {
		if (elephant_check(x, y, pieces, queen) == 0
		|| rook_check(x, y, pieces, queen) == 0) {
			queen->x = x;
			queen->y = y;
			kill->dead = 1;
			return 0;
		}
	}
	return -1;
}

int check_end(piece *pieces)
{
	for (int i = 0; i < 36; i++) {
		if (pieces[i].type == 'K' || pieces[i].type == 'k') {
			if (pieces[i].dead != 1)
				return 0;
		}
	}
	return -1;
}