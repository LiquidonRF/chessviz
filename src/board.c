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

int get_move(piece *p, char x, char y)
{
	if (x <= 'h' && x >= 'a' && y <= '8' && y >= '1'){
		p->x = x;
		p->y = y;
		return 0;
	}
	return -1;
}

int get_move_pawn(piece *pieces, char x, char y)
{
	if (isupper(pieces->type)){											//Для белых
		if (pieces->x == x){
			if (pieces->y == '2'){									//С начальной позиции
				if ((y - pieces->y) == 2){							//Движение на 2 клетки
					get_move(pieces, x, y);
					return 0;
				}
				if ((y - pieces->y) == 1){							//Движение на 2 клетки
					get_move(pieces, x, y);
					return 0;
				}
			} else {
				if ((y - pieces->y) == 1){							//Движение на одну клетку
					get_move(pieces, x, y);
					return 0;
				}
			}
		}
	} else {				
		if (pieces->x == x){										//Для черных
			if (pieces->y == '7'){									//С начальной позиции
				if ((pieces->y - y) == 2){  						//Движение на две клетки
					get_move(pieces, x, y);
					return 0;
				}
				if ((pieces->y - y) == 1){							//Движение на 2 клетки
					get_move(pieces, x, y);
					return 0;
				}
			} else {
				if ((y - pieces->y) == 1){							//Движение на одну клетку
					get_move(pieces, x, y);
					return 0;
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

// int is_piece_in_coord(char x, char y, pawn *pawns)
// {
// 	if (search_pawn(x, y, pawns) == NULL)
// 		return -1;

// 	return 0;
// }