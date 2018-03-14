#include "piece.h"

int get_move(piece *p, char *x, char *y)
{
	if (x <= 'h' && x >= 'a' && y <= 8 && y>= 1){
		p->x = x;
		p->y = y;
	}
}

int get_move_pawn(pawn *pawn, char *x, char *y)
{
	if (pawn->color == 1){											//Для белых
		if (pawn->p->x == *x){
			if (pawn->p->y == 2){									//С начальной позиции
				if ((y - pawn->p->y) == 2)							//Движение на 2 клетки
					get_move(pawn->p, x, y);
			} else {
				if ((y - pawn->p->y) == 1){							//Движение на одну клетку
					get_move(pawn->p, x, y);
				}
			}
		}
	} else {				
		if (pawn->p->x == *x){										//Для черных
			if (pawn->p->y == 7){									//С начальной позиции
				if ((pawn->p->y - y) == 2)							//Движение на две клетки
					get_move(pawn->p, x, y);
			} else {
				if ((y - pawn->p->y) == 1){							//Движение на одну клетку
					get_move(pawn->p, x, y);
			}
		}
	}
}