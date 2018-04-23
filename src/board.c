#include "board.h"

piece *pieces_init()
{
	piece *pieces = (piece *)malloc(sizeof(pieces) * 16);

	char key = 'a';

	for (int i = 0; i < 16; i+=2) {
		pieces[i].type = 'p';
		pieces[i + 1].type = 'P';
		pieces[i].y = '7';
		pieces[i + 1].y = '2';
		pieces[i].x = key;
		pieces[i + 1].x = key;
		key++;
	}
	return pieces;
}

void get_move(piece *p, char x, char y)
{
		p->x = x;
		p->y = y;
}

int get_move_pawn(piece *pieces, piece *pawn, char x, char y)
{
	if (x <= 'h' && x >= 'a' && y <= '8' && y >= '1'){
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
	}
	return -1;
}

piece *search_piece(char x, char y, piece *pieces)
{
	for (int i = 0; i < 16; i++) {
		if (pieces[i].x == x && pieces[i].y == y){
			return &pieces[i];
		}
	}
	return NULL;
}

int get_move_rook(char x, char y, piece *pieces, piece *rook)
{
	if (x <= 'h' && x >= 'a' && y <= '8' && y >= '1'){
		if (rook->x == x) {
			if (y < rook->y) {
				for (int i = y - '1'; i <= rook->y - '1'; i++) {
					if (search_piece(x, i, pieces) != NULL) {
						return -1;
					}
				}
				get_move(pieces, x, y);
			} else if (y > rook->y) {
				for (int i = rook->y - '1'; i <= y - '1'; i++) {
					if (search_piece(x, i, pieces) != NULL) {
						return -1;
					}
				}
				get_move(pieces, x, y);
				return 0;
			}
		} else if (rook->y == y) {
			if (x < rook->x) {
				for (int i = x - 'a'; i <= rook->x - 'a'; i++) {
					if (search_piece(i, y, pieces) != NULL) {
						return -1;
					}
				}
				get_move(pieces, x, y);
			} else if (x > rook->x) {
				for (int i = rook->x - 'a'; i <= x - 'a'; i++) {
					if (search_piece(i, y, pieces) != NULL) {
						return -1;
					}
				}
				get_move(pieces, x, y);
				return 0;
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