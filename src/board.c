#include "board.h"

piece *pieces_init()
{
	piece *pieces = (piece *)malloc(sizeof(pieces) * 20);

	char key = 'a';

	for (int i = 0; i < 16; i += 2) {
		pieces[i].type = 'p';
		pieces[i + 1].type = 'P';
		pieces[i].y = '7';
		pieces[i + 1].y = '2';
		pieces[i].x = key;
		pieces[i + 1].x = key;
		key++;
	}

		pieces[16].type = 'r';
		pieces[17].type = 'R';
		pieces[16].y = '8';
		pieces[17].y = '1';
		pieces[16].x = 'a';
		pieces[17].x = 'h';
		pieces[18].type = 'r';
		pieces[19].type = 'R';
		pieces[18].y = '8';
		pieces[19].y = '1';
		pieces[18].x = 'h';
		pieces[19].x = 'a';

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
		if (isupper(pawn->type)) {											//Для белых
			if (pawn->x == x && y > pawn->y){
				if (pawn->y == '2'){									//С начальной позиции
					if ((y - pawn->y) == 2){							//Движение на 2 клетки
						get_move(pawn, x, y);
						return 0;
					}
					if ((y - pawn->y) == 1){							//Движение на 2 клетки
						get_move(pawn, x, y);
						return 0;
					}
				} else {
					if ((y - pawn->y) == 1){							//Движение на одну клетку
						get_move(pawn, x, y);
						return 0;
					}
				}
			}
		} else {				
			if (pawn->x == x && y < pawn->y){										//Для черных
				if (pawn->y == '7'){									//С начальной позиции
					if ((pawn->y - y) == 2){  						//Движение на две клетки
						get_move(pawn, x, y);
						return 0;
					}
					if ((pawn->y - y) == 1){							//Движение на 2 клетки
						get_move(pawn, x, y);
						return 0;
					}
				} else {
					if ((y - pawn->y) == 1){							//Движение на одну клетку
						get_move(pawn, x, y);
						return 0;
					}
				}
			}
		}
	}
	return -1;
}

piece *search_piece(char x, char y, piece *pieces)
{
	for (int i = 0; i < 20; i++) {
		if (pieces[i].x == x && pieces[i].y == y){
			return &pieces[i];
		}
	}
	return NULL;
}

int get_move_rook(char x, char y, piece *pieces, piece *rook)
{
	if (rook->x == x) {
		if (y < rook->y) {
			for (int i = y - '1'; i < rook->y - '1'; i++) {
				printf("%c\n", i + '1');
				if (search_piece(x, i + '1', pieces) != NULL) {
					return -1;
				}
			}
			get_move(rook, x, y);
			return 0;
		} else if (y > rook->y) {
			for (int i = rook->y - '1' + 1; i < y - '1' + 1; i++) {
				printf("%c\n", i + '1');
				if (search_piece(x, i + '1', pieces) != NULL) {
					return -1;
				}
			}
			get_move(rook, x, y);
			return 0;
		}
	} else if (rook->y == y) {
		if (x < rook->x) {
			for (int i = x - 'a'; i < rook->x - 'a'; i++) {
				printf("%c\n", i + 'a');
				if (search_piece(i + 'a', y, pieces) != NULL) {
					return -1;
				}
			}
			get_move(rook, x, y);
			return 0;
		} else if (x > rook->x) {
			for (int i = rook->x - 'a' + 1; i < x - 'a' + 1; i++) {
				printf("%c\n", i + 'a');
				if (search_piece(i + 'a', y, pieces) != NULL) {
					return -1;
				}
			}
			get_move(rook, x, y);
			return 0;
		}
	}
	return -1;
}

int get_turn(piece *pieces, int turn)
{
	char command[10];
	printf("Enter turn: ");
	scanf("%s", command);
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
			}
		}
	}
	return -1;
}

// int is_piece_in_coord(char x, char y, pawn *pawns)
// {
// 	if (search_pawn(x, y, pawns) == NULL)
// 		return -1;

// 	return 0;
// }