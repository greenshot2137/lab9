#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

// zmienia wartości wierszy dla każdego miejsca do wyzerowania
void substract_rows(Matrix* mat, Matrix* b, int d);

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);

#endif