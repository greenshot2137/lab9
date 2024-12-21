#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>

// zwraca główny element dla danej kolumny macierzy
int get_main_elem(Matrix* mat, int col)
{
	double main_elem_val = abs(mat->data[0][col]);
	int main_elem = 0;

	for(int i = 0; i < mat->r; i++)
		if(abs(mat->data[i][col]) > main_elem_val)
		{
			main_elem_val = abs(mat->data[i][col]);
			main_elem = i;
		}

	return main_elem;
}

// zamienia wiersze tak, by główny element był na diagonalu
void switch_rows(Matrix* mat, Matrix* b, int main_elem, int col)
{
	if(main_elem != col)
	{
		double tmp;
		for(int i = col; i < mat->c; i++)
		{
			tmp = mat->data[0][i];
			mat->data[0][i] = mat->data[main_elem][i];
			mat->data[main_elem][i] = tmp; 
		}
		tmp = b->data[0][0];
		b->data[0][0] = b->data[main_elem][0];
		b->data[main_elem][0] = tmp;
	}
}

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
		// zwraca główny element
		int main_elem = get_main_elem(mat, d);

		// zamienia wiersze
		switch_rows(mat, b, main_elem, d);

		// obsłuża przypadek dla zera i zwraca 1
		if(mat->data[d][d] == 0)
			return 1;

		// zmienia wartości wierszy
		substract_rows(mat, b, d);
	}

	return 0;
}