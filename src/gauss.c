#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>

// zmienia wartości wierszy dla każdego miejsca do wyzerowania
void substract_rows(Matrix* mat, Matrix* b, int d)
{
	for(int r = d + 1; r < mat->r; r++)
	{
		// oblicza skalar
		double scalar = mat->data[r][d] / mat->data[d][d];

		// zmienia wartości wiersza r
		for(int col = 0; col < mat->c; col++)
			mat->data[r][col] -= scalar * mat->data[d][col];
		
		b->data[r][0] -= scalar * b->data[d][0];
	}
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	// dla każdej kolumny (indeksów diagonala)
    for(int d = 0; d < mat->r; d++)
	{
		// obsłuża przypadek dla zera i zwraca 1
		if(mat->data[d][d] == 0)
			return 1;

		// zmienia wartości wierszy
		substract_rows(mat, b, d);
	}

	return 0;
}