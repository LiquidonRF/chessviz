#include "board.h"

pawn *pawn_init()
{
	pawn *pawns = (pawn *)malloc(sizeof(pawn) * 16);

	char key = 'a';

	for (int i = 0; i < 16; i+=2)
	{
		pawns[i].color = 0;
		pawns[i + 1].color = 1;
		pawns[i].p.y = '7';
		pawns[i + 1].p.y = '2';
		pawns[i].p.x = key;
		pawns[i + 1].p.x = key;
		key++;
	}
	return pawns;
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

int get_move_pawn(pawn *pawn, char x, char y)
{
	if (pawn->color == 1){											//Для белых
		if (pawn->p.x == x){
			if (pawn->p.y == '2'){									//С начальной позиции
				if ((y - pawn->p.y) == 2){							//Движение на 2 клетки
					get_move(&pawn->p, x, y);
					return 0;
				}
				if ((y - pawn->p.y) == 1){							//Движение на 2 клетки
					get_move(&pawn->p, x, y);
					return 0;
				}
			} else {
				if ((y - pawn->p.y) == 1){							//Движение на одну клетку
					get_move(&pawn->p, x, y);
					return 0;
				}
			}
		}
	} else {				
		if (pawn->p.x == x){										//Для черных
			if (pawn->p.y == '7'){									//С начальной позиции
				if ((pawn->p.y - y) == 2){  						//Движение на две клетки
					get_move(&pawn->p, x, y);
					return 0;
				}
			} else {
				if ((y - pawn->p.y) == 1){							//Движение на одну клетку
					get_move(&pawn->p, x, y);
					return 0;
				}
			}
		}
	}
	return -1;
}

pawn *search_pawn(char x, char y, pawn *pawns)
{
	for (int i = 0; i < 16; i++)
	{
		if (pawns[i].p.x == x && pawns[i].p.y == y){
			return &pawns[i];
		}
	}
	return NULL;
}